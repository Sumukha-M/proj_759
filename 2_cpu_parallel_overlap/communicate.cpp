//==============================================
// File: communicate.cpp
// Description: Implements compute_gradients function.
// Simulates backward pass gradient computation with delays.
//==============================================

#include <iostream>
#include <thread>
#include <chrono>

void compute_gradients() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "[GradCompute] Layer " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Simulate compute delay
    }
}
