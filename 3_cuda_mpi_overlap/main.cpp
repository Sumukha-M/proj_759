//==============================================
// File: main.cpp
// Description: Entry point for CUDA-MPI-OpenMP Overlap Simulation.
// - Initializes MPI environment.
// - Uses OpenMP to overlap gradient computation and communication.
// - Finalizes MPI after execution.
//==============================================

#include <mpi.h>
#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "backward.h"
#include "allreduce.h"

// Define gradient array size
const int D = 512;

int main(int argc, char** argv) {
    // Initialize MPI environment
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   // Get current process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size);   // Get total number of processes

    float grad[D];  // Gradient array shared across threads

    // Parallel sections using OpenMP to overlap compute and communication
#pragma omp parallel sections
    {
#pragma omp section
        {
            // Simulate backward pass (gradient computation)
            fake_backward(grad);
            std::cout << "[Rank " << rank << "] Grad computed" << std::endl;
        }
#pragma omp section
        {
            // Simulate communication delay before AllReduce
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            // Simulate AllReduce communication
            fake_allreduce(grad, rank, size);
            std::cout << "[Rank " << rank << "] Grad AllReduced" << std::endl;
        }
    }

    // Finalize MPI environment
    MPI_Finalize();

    return 0;
}
