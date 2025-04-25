#include <iostream>          // For standard I/O operations
#include <cmath>             // For sin() and cos() functions
#include <cuda_runtime.h>    // CUDA runtime API

// Declare external CUDA kernel functions (definitions are in other files)
__global__ void matmul_forward(float* x, float* w, float* y);   // Forward pass kernel
__global__ void matmul_backward(float* grad_out, float* x, float* grad_w);  // Backward pass kernel
__global__ void sgd_update(float* w, float* grad_w, float lr);  // SGD weight update kernel

// Define constants for batch size (N) and feature dimension (D)
#define N 1024
#define D 512

int main() {
    // Declare pointers for input, weights, output, gradients, and learning rate
    float *x, *w, *y, *grad_out, *grad_w;
    float lr = 0.001f;   // Learning rate for SGD

    // Allocate unified memory accessible by both CPU and GPU
    cudaMallocManaged(&x, N * D * sizeof(float));        // Input matrix
    cudaMallocManaged(&w, D * D * sizeof(float));        // Weight matrix
    cudaMallocManaged(&y, N * D * sizeof(float));        // Output matrix
    cudaMallocManaged(&grad_out, N * D * sizeof(float)); // Gradient from next layer
    cudaMallocManaged(&grad_w, D * D * sizeof(float));   // Gradient w.r.t weights

    // Initialize input 'x' with sine values and weights 'w' with cosine values
    for (int i = 0; i < N * D; ++i) 
        x[i] = sin(i);

    for (int i = 0; i < D * D; ++i) 
        w[i] = cos(i);

    // Define CUDA kernel launch parameters
    dim3 threads(256);             // 256 threads per block
    dim3 blocks((N + 255) / 256);  // Calculate number of blocks needed for N elements

    // Launch forward pass kernel: y = x * w
    matmul_forward<<<blocks, threads>>>(x, w, y);
    cudaDeviceSynchronize();   // Wait for GPU to finish

    // Set dummy gradient output (simulate backpropagation input)
    for (int i = 0; i < N * D; ++i) 
        grad_out[i] = 1.0f;

    // Launch backward pass kernel to compute gradient w.r.t weights
    matmul_backward<<<(D + 255) / 256, threads>>>(grad_out, x, grad_w);
    cudaDeviceSynchronize();   // Wait for GPU to finish

    // Launch SGD update kernel to adjust weights based on gradients
    sgd_update<<<(D * D + 255) / 256, threads>>>(w, grad_w, lr);
    cudaDeviceSynchronize();   // Wait for GPU to finish

    // Print completion message
    std::cout << "One training iteration complete." << std::endl;

    // Free allocated unified memory
    cudaFree(x); 
    cudaFree(w); 
    cudaFree(y); 
    cudaFree(grad_out); 
    cudaFree(grad_w);

    return 0;   // Exit program
}
