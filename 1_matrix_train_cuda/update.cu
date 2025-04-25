#include <cuda_runtime.h>   // CUDA runtime API for kernel execution

#define D 512   // Define matrix dimension (D x D weights)

// CUDA kernel to perform SGD weight update
__global__ void sgd_update(float* w, float* grad_w, float lr) {
    // Calculate global thread index
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // Ensure thread operates within valid range
    if (idx < D * D)
        w[idx] -= lr * grad_w[idx];   // Perform weight update: w = w - lr * grad_w
}
