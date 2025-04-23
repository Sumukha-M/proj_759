#include <iostream>
#include <cmath>
#include <cuda_runtime.h>

// Declare kernel functions from other files
__global__ void matmul_forward(float* x, float* w, float* y);
__global__ void matmul_backward(float* grad_out, float* x, float* grad_w);
__global__ void sgd_update(float* w, float* grad_w, float lr);

#define N 1024
#define D 512

int main() {
    float *x, *w, *y, *grad_out, *grad_w;
    float lr = 0.001f;
}
