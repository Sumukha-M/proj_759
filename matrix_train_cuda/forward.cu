#include <cuda_runtime.h>
#include <stdio.h>

#define N 1024
#define D 512

__global__ void matmul_forward(float* x, float* w, float* y) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // Work only if thread index is within matrix row bounds
    if (idx < N) {
        // Future matrix computation will go here
    }
}
