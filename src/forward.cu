#include <cuda_runtime.h>
#include <cstdio>
#include <cmath>

// ---------------------------------------------
// CUDA Kernels
// ---------------------------------------------

// Linear layer: output = input × weight^T + bias
__global__ void linear_forward(float* input, float* weight, float* bias, float* output,
                               int batch_size, int in_features, int out_features) {
    int row = blockIdx.y * blockDim.y + threadIdx.y; // which input in batch
    int col = blockIdx.x * blockDim.x + threadIdx.x; // which neuron (output feature)

    if (row < batch_size && col < out_features) {
        float sum = 0.0f;
        for (int i = 0; i < in_features; ++i) {
            sum += input[row * in_features + i] * weight[col * in_features + i];  // weight[output, input]
        }
        output[row * out_features + col] = sum + bias[col];
    }
}

// ReLU activation: element-wise max(0, x)
__global__ void relu_forward(float* input, float* output, int size) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < size) {
        output[idx] = fmaxf(0.0f, input[idx]);
    }
}

// ---------------------------------------------
// Kernel Launchers (externally callable)
// ---------------------------------------------

// Wrapper to launch linear layer
void launch_linear_forward(float* input, float* weight, float* bias, float* output,
                           int batch_size, int in_features, int out_features) {
    dim3 threadsPerBlock(16, 16);
    dim3 blocksPerGrid((out_features + 15) / 16, (batch_size + 15) / 16);
    linear_forward<<<blocksPerGrid, threadsPerBlock>>>(input, weight, bias, output,
                                                       batch_size, in_features, out_features);
}

// Wrapper to launch ReLU
void launch_relu_forward(float* input, float* output, int size) {
    int blockSize = 256;
    int gridSize = (size + blockSize - 1) / blockSize;
    relu_forward<<<gridSize, blockSize>>>(input, output, size);
}
