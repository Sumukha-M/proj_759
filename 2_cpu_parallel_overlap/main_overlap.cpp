#include <omp.h>
#include <iostream>
#include <chrono>
#include "compute.h"
#include "communicate.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // ---- Overlapped Execution using OpenMP ----
#pragma omp parallel sections
    {
#pragma omp section
        {
            compute_gradients();
        }
#pragma omp section
        {
            communicate_gradients();
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "[Overlapped Execution Time]: " << elapsed.count() << " ms" << std::endl;

    return 0;
}
