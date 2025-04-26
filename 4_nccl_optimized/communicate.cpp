#include <iostream>
#include <thread>
#include <chrono>
#include "communicate.h"

// Simulate NCCL AllReduce for a given chunk
void mock_allreduce(int chunk_id) {
    std::cout << "[Comm] AllReducing gradients for chunk " << chunk_id << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Simulate communication time
}
