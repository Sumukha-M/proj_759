
#include <iostream>
#include <omp.h>
#include <thread>
#include <chrono>

void compute_gradients() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "[GradCompute] Layer " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void communicate_gradients() {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "[Comm] AllReduce for Layer " << i << std::endl;
    }
}

int main() {
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
    return 0;
}
