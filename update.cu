#include <cuda_runtime.h>

#define D 512

__global__ void sgd_update(float* w, float* grad_w, float lr) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < D * D)
        w[idx] -= lr * grad_w[idx];
}