#include <iostream>
#include <chrono>
#include "compute.h"
#include "communicate.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // ---- Sequential Execution ----
    compute_gradients();
    communicate_gradients();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "[Sequential Execution Time]: " << elapsed.count() << " ms" << std::endl;

    return 0;
}
