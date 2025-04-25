#include <cuda_runtime.h>
#include <stdio.h>

#define N 1024
#define D 512

__global__ void matmul_forward(float* x, float* w, float* y) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    if (idx < N) {
        for (int j = 0; j < D; ++j) {
            y[idx * D + j] = 0;

            // Dot product: idx-th row of x and j-th column of w
            for (int k = 0; k < D; ++k) {
                y[idx * D + j] += x[idx * D + k] * w[k * D + j];
            }
        }
    }
}
