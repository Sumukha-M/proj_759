#include <cuda_runtime.h>
#include <stdio.h>

#define N 1024
#define D 512

_global_ void matmul_forward(float* x, float* w, float* y) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < N) {
        for (int j = 0; j < D; ++j) {
            y[idx * D + j] = 0;
            for (int k = 0; k < D; ++k)
                y[idx * D + j] += x[idx * D + k] * w[k * D + j]; //dot product of idth row of x and jth col of w
        }
    }
}
