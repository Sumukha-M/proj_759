#include <cuda_runtime.h>
#include <cstdio>

__global__ void linear_forward(float* input, float* weight, float* bias, float* output,
                               int batch_size, int in_features, int out_features) {
    int row = blockIdx.y * blockDim.y + threadIdx.y; // output row (batch)
    int col = blockIdx.x * blockDim.x + threadIdx.x; // output col (neuron)

    if (row < batch_size && col < out_features) {
        float sum = 0.0f;
        for (int i = 0; i < in_features; ++i) {
            sum += input[row * in_features + i] * weight[col * in_features + i]; // weight is [out, in]
        }
        output[row * out_features + col] = sum + bias[col];
    }
}