#include <cuda_runtime.h>
#include <stdio.h>

// Define matrix dimensions
#define N 1024  // Number of rows in input matrix x (and output matrix y)
#define D 512   // Number of columns in x, rows and columns in weight matrix w

// CUDA kernel to perform matrix multiplication y = x * w
// x: [N x D], w: [D x D], y: [N x D]
__global__ void matmul_forward(float* x, float* w, float* y) {
    // Calculate the global thread index
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // Only allow threads corresponding to valid row indices of x
    if (idx < N) {
        // Iterate over each column of the output matrix y
        for (int j = 0; j < D; ++j) {
            // Initialize the output element y[idx][j] to zero
            y[idx * D + j] = 0;

            // Compute dot product between the idx-th row of x and j-th column of w
            for (int k = 0; k < D; ++k) {
                // x[idx][k] * w[k][j]
                y[idx * D + j] += x[idx * D + k] * w[k * D + j];
            }
        }
    }
}
