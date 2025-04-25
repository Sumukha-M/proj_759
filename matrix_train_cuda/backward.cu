#include <cuda_runtime.h>

#define N 1024  // Batch size (number of data samples)
#define D 512   // Feature dimension

// CUDA kernel to compute gradient of weights (grad_w) for a matrix multiplication backward pass
__global__ void matmul_backward(float* grad_out, float* x, float* grad_w) {
    // Compute the thread index in 1D
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // Each thread computes the row idx of the grad_w matrix
    if (idx < D) {
        for (int j = 0; j < D; ++j) {
            // Initialize grad_w[idx][j] to 0 before accumulation
            grad_w[idx * D + j] = 0;

            // Accumulate gradient
            for (int b = 0; b < N; ++b)
                grad_w[idx * D + j] += x[b * D + idx] * grad_out[b * D + j];
        }
    }
}
