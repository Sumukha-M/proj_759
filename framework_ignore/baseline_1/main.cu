
#include <cuda_runtime.h>
#include <iostream>
#include <cmath>

#define N 1024  // batch size
#define D 512   // input/output size

__global__ void matmul_forward(float* x, float* w, float* y) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < N) {
        for (int j = 0; j < D; ++j) {
            y[idx * D + j] = 0;
            for (int k = 0; k < D; ++k)
                y[idx * D + j] += x[idx * D + k] * w[k * D + j];
        }
    }
}

__global__ void matmul_backward(float* grad_out, float* x, float* grad_w) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < D) {
        for (int j = 0; j < D; ++j) {
            grad_w[idx * D + j] = 0;
            for (int b = 0; b < N; ++b)
                grad_w[idx * D + j] += x[b * D + idx] * grad_out[b * D + j];
        }
    }
}

__global__ void sgd_update(float* w, float* grad_w, float lr) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < D * D)
        w[idx] -= lr * grad_w[idx];
}

int main() {
    float *x, *w, *y, *grad_out, *grad_w;
    float lr = 0.001;

    cudaMallocManaged(&x, N * D * sizeof(float));
    cudaMallocManaged(&w, D * D * sizeof(float));
    cudaMallocManaged(&y, N * D * sizeof(float));
    cudaMallocManaged(&grad_out, N * D * sizeof(float));
    cudaMallocManaged(&grad_w, D * D * sizeof(float));

    for (int i = 0; i < N * D; ++i) x[i] = sin(i);
    for (int i = 0; i < D * D; ++i) w[i] = cos(i);

    dim3 threads(256);
    dim3 blocks((N + 255) / 256);

    matmul_forward<<<blocks, threads>>>(x, w, y);
    cudaDeviceSynchronize();

    for (int i = 0; i < N * D; ++i) grad_out[i] = 1.0f;

    matmul_backward<<<(D + 255) / 256, threads>>>(grad_out, x, grad_w);
    cudaDeviceSynchronize();

    sgd_update<<<(D * D + 255) / 256, threads>>>(w, grad_w, lr);
    cudaDeviceSynchronize();

    std::cout << "One training iteration complete." << std::endl;

    cudaFree(x); cudaFree(w); cudaFree(y); cudaFree(grad_out); cudaFree(grad_w);
    return 0;
}
