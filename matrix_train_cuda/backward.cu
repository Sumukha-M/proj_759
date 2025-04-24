#include <cuda_runtime.h>

#define N 1024
#define D 512

__global__ void matmul_backward(float* grad_out, float* x, float* grad_w) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // Just a placeholder loop
    if (idx < D) {
        for (int j = 0; j < D; ++j) {
            grad_w[idx * D + j] = 1.0; // Dummy value
        }
    }
}
