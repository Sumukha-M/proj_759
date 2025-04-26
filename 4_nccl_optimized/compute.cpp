#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "compute.h"

void compute_gradients(int chunk_id) {
    int delay = 300 + rand() % 50;  // 300ms ± 50ms variability
    std::cout << "[Compute] Computing gradients for chunk " << chunk_id << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}
