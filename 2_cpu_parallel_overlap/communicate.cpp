//==============================================
// File: communicate.cpp
// Description: Implements communicate_gradients function.
// Simulates communication (AllReduce) with delays.
//==============================================

#include <iostream>
#include <thread>
#include <chrono>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simulate communication delay
        std::cout << "[Comm] AllReduce for Layer " << i << std::endl;
    }
}
