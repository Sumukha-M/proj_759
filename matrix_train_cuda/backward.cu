#include <cuda_runtime.h>

#define N 1024
#define D 512

__global__ void matmul_backward(float* grad_out, float* x, float* grad_w) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    if (idx < D) {
        for (int j = 0; j < D; ++j) {
            float sum = 0;
            for (int b = 0; b < N; ++b) {
                sum += x[b * D + idx];  // Grad output not used yet
            }
            grad_w[idx * D + j] = sum;
        }
    }
}
