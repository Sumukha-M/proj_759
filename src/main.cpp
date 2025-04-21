#include <iostream>
#include <torch/torch.h>
#include <torch/script.h>
#include <cuda_runtime.h>

extern void launch_linear_forward(float* input, float* weight, float* bias, float* output,
                                  int batch_size, int in_features, int out_features);
extern void launch_relu_forward(float* input, float* output, int size);

// Error checking
#define cudaCheckError(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line) {
    if (code != cudaSuccess)
        std::cerr << "CUDA Error: " << cudaGetErrorString(code) << " " << file << " " << line << std::endl;
}

int main() {
    // -------------------- Load baseline.pt --------------------
    torch::NoGradGuard no_grad;

    // Load as IValue instead of Module
    torch::IValue obj;
    torch::load(obj, "data/baseline.pt");

    // Convert to generic dict
    auto data = obj.toGenericDict();

    torch::Tensor input     = data.at("input").toTensor().contiguous();
    torch::Tensor weight    = data.at("layer0_weight").toTensor().contiguous();
    torch::Tensor bias      = data.at("layer0_bias").toTensor().contiguous();
    torch::Tensor ref_out   = data.at("output").toTensor().contiguous();  // PyTorch output

    int batch_size = input.size(0);
    int in_features = input.size(1);
    int out_features = weight.size(0);

    std::cout << "Loaded input of shape: " << input.sizes() << "\n";

    // -------------------- Allocate and copy to device --------------------
    float *d_input, *d_weight, *d_bias, *d_output, *d_relu;
    cudaMalloc(&d_input,  input.numel() * sizeof(float));
    cudaMalloc(&d_weight, weight.numel() * sizeof(float));
    cudaMalloc(&d_bias,   bias.numel() * sizeof(float));
    cudaMalloc(&d_output, batch_size * out_features * sizeof(float));
    cudaMalloc(&d_relu,   batch_size * out_features * sizeof(float));

    cudaMemcpy(d_input,  input.data_ptr<float>(), input.numel() * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_weight, weight.data_ptr<float>(), weight.numel() * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_bias,   bias.data_ptr<float>(), bias.numel() * sizeof(float), cudaMemcpyHostToDevice);

    // -------------------- Run CUDA kernels --------------------
    launch_linear_forward(d_input, d_weight, d_bias, d_output, batch_size, in_features, out_features);
    launch_relu_forward(d_output, d_relu, batch_size * out_features);

    // -------------------- Copy back --------------------
    std::vector<float> h_output(batch_size * out_features);
    cudaMemcpy(h_output.data(), d_relu, h_output.size() * sizeof(float), cudaMemcpyDeviceToHost);

    // -------------------- Compare with PyTorch output --------------------
    auto ref_flat = ref_out.view({-1}).contiguous();
    auto ref_ptr = ref_flat.data_ptr<float>();

    std::cout << "CUDA Output vs PyTorch Output (first 10 values):\n";
    for (int i = 0; i < std::min(10, (int)h_output.size()); ++i) {
        std::cout << "CUDA: " << h_output[i] << " \t PyTorch: " << ref_ptr[i] << "\n";
    }

    // -------------------- Cleanup --------------------
    cudaFree(d_input); cudaFree(d_weight); cudaFree(d_bias);
    cudaFree(d_output); cudaFree(d_relu);

    return 0;
}