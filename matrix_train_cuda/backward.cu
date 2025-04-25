#include <cuda_runtime.h>

#define N 1024  // Batch size (number of data samples)
#define D 512   // Feature dimension

// CUDA kernel to compute gradient of weights (grad_w) for a matrix multiplication backward pass

// This computes: grad_w = x^T * grad_out
_global_ void matmul_backward(float* grad_out, float* x, float* grad_w) {
    // Compute the global thread index (each thread handles one row of grad_w)

__global__ void matmul_backward(float* grad_out, float* x, float* grad_w) {
    // Compute the thread index in 1D

    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // Ensure the thread operates only within valid feature dimensions
    if (idx < D) {
        // Loop over each column of grad_w
        for (int j = 0; j < D; ++j) {
            // Initialize the (idx, j) element of grad_w to zero before accumulation
            grad_w[idx * D + j] = 0.0f;

            // Perform the dot product of:
            // - idx-th column of input matrix x (since x^T is involved)
            // - j-th column of grad_out
            //
            // This loop runs over the batch dimension to accumulate contributions
            for (int b = 0; b < N; ++b) {
                // Accumulate: grad_w[idx][j] += x[b][idx] * grad_out[b][j]
                grad_w[idx * D + j] += x[b * D + idx] * grad_out[b * D + j];
            }
        }
    }
}
