//==============================================
// File: communicate.cpp
// Description: Implements compute_gradients function.
// Simulates backward pass gradient computation with delays.
// Note: This function simulates latency for each layer's computation.
//==============================================

#include <iostream>
#include <thread>
#include <chrono>

// Function: compute_gradients
// Purpose:
// - Simulates a simple backward pass over 5 layers
// - Outputs processing status to console
// - Introduces 200ms delay after each layer to mimic computation
void compute_gradients() {
    for (int i = 0; i < 5; ++i) {
        // Log the current layer being computed
        std::cout << "[GradCompute] Layer " << i << std::endl;

        // Wait to simulate compute time
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  
    }
}
