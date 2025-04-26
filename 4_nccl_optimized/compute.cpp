#include <iostream>
#include <thread>
#include <chrono>
#include "compute.h"

// Simulate gradient computation for a given chunk
void compute_gradients(int chunk_id) {
    std::cout << "[Compute] Computing gradients for chunk " << chunk_id << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));  // Simulate compute time
}
