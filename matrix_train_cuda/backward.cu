#include <cuda_runtime.h>

#define N 1024
#define D 512

_global_ void matmul_backward(float* grad_out, float* x, float* grad_w) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < D) {
        for (int j = 0; j < D; ++j) {
            grad_w[idx * D + j] = 0;
            for (int b = 0; b < N; ++b)
                grad_w[idx * D + j] += x[b * D + idx] * grad_out[b * D + j];
        }
    }
}