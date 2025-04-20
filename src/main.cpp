#include <iostream>
#include <vector>
#include <cuda_runtime.h>

extern void launch_linear_forward(float* input, float* weight, float* bias, float* output,
                                  int batch_size, int in_features, int out_features);
extern void launch_relu_forward(float* input, float* output, int size);

// Helper for error checking
#define cudaCheckError(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line) {
    if (code != cudaSuccess)
        std::cerr << "CUDA Error: " << cudaGetErrorString(code) << " " << file << " " << line << std::endl;
}

int main() {
    int batch_size = 2;
    int in_features = 4;
    int out_features = 3;

    float h_input[]  = {1, 2, 3, 4, 5, 6, 7, 8};  // shape: [2 x 4]
    float h_weight[] = {1, 1, 1, 1,   // neuron 1
                        0, 0, 1, 0,   // neuron 2
                        1, 0, 0, 0};  // neuron 3
    float h_bias[]   = {1, 2, 3};     // shape: [3]
    float h_output[6];                // shape: [2 x 3]

    // Allocate device memory
    float *d_input, *d_weight, *d_bias, *d_output;
    cudaMalloc(&d_input, sizeof(h_input));
    cudaMalloc(&d_weight, sizeof(h_weight));
    cudaMalloc(&d_bias, sizeof(h_bias));
    cudaMalloc(&d_output, sizeof(h_output));

    // Copy to device
    cudaMemcpy(d_input, h_input, sizeof(h_input), cudaMemcpyHostToDevice);
    cudaMemcpy(d_weight, h_weight, sizeof(h_weight), cudaMemcpyHostToDevice);
    cudaMemcpy(d_bias, h_bias, sizeof(h_bias), cudaMemcpyHostToDevice);

    // Launch kernel
    launch_linear_forward(d_input, d_weight, d_bias, d_output, batch_size, in_features, out_features);

    // Copy back result
    cudaMemcpy(h_output, d_output, sizeof(h_output), cudaMemcpyDeviceToHost);
    std::cout << "Linear Output:\n";
    for (int i = 0; i < 6; ++i) std::cout << h_output[i] << " ";
    std::cout << "\n";

    // ReLU
    float h_relu_out[6];
    float *d_relu_out;
    cudaMalloc(&d_relu_out, sizeof(h_output));
    launch_relu_forward(d_output, d_relu_out, 6);
    cudaMemcpy(h_relu_out, d_relu_out, sizeof(h_relu_out), cudaMemcpyDeviceToHost);

    std::cout << "ReLU Output:\n";
    for (int i = 0; i < 6; ++i) std::cout << h_relu_out[i] << " ";
    std::cout << "\n";

    // Free memory
    cudaFree(d_input); cudaFree(d_weight); cudaFree(d_bias);
    cudaFree(d_output); cudaFree(d_relu_out);

    return 0;
}
