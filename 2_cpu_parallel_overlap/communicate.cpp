//==============================================
// File: communicate.cpp
// Description: Implements compute_gradients function.
// Simulates backward pass gradient computation with delays.
// Note: This function is used for simulating compute delay in multi-threaded scenarios.
//==============================================

#include <iostream>
#include <thread>
#include <chrono>

// compute_gradients:
// - Iterates through 5 virtual layers
// - Prints a message for each layer
// - Waits for 200ms after processing each layer
void compute_gradients() {
    // Iterate over each virtual layer
    for (int i = 0; i < 5; ++i) {
        // Log current layer number
        std::cout << "[GradCompute] Layer " << i << std::endl;

        // Simulate compute delay
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  
    }
}
