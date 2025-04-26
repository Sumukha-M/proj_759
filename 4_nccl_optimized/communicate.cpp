#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "communicate.h"

void mock_allreduce(int chunk_id) {
    int delay = 200 + rand() % 30;  // 200ms ± 30ms variability
    std::cout << "[Comm] AllReducing gradients for chunk " << chunk_id << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}
