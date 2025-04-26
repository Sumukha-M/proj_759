//==============================================
// File: allreduce.cpp
// Description: Implements fake_allreduce function.
// This function simulates an MPI AllReduce operation by:
// 1. Introducing artificial delay to mimic communication time.
// 2. Scaling gradient values based on the number of processes.
//==============================================

#include <thread>
#include <chrono>
#include "allreduce.h"

// Define the gradient size (must match main.cpp)
const int D = 512;

// Simulate AllReduce communication
void fake_allreduce(float* grad, int rank, int size) {
    // Simulate communication delay (150 ms)
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    // Dummy AllReduce operation: Scale gradient by number of processes
    for (int i = 0; i < D; ++i) {
        grad[i] *= size;
    }
}
