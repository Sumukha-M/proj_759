//==============================================
// File: communicate.cpp
// Description: Implements compute_gradients function.
// Simulates backward pass gradient computation with delays.
// Note: This function is used for testing parallel compute workloads.
//==============================================

#include <iostream>
#include <thread>
#include <chrono>

void compute_gradients() {
    // Iterate over each layer and simulate processing time
    for (int i = 0; i < 5; ++i) {
        // Print current layer number
        std::cout << "[GradCompute] Layer " << i << std::endl;

        // Sleep for 200ms to mimic compute workload
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  
    }
}
