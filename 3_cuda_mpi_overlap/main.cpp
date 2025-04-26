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

int main() {
    // Initialize MPI environment
    MPI_Init(0, 0);  // WRONG: should be &argc, &argv

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   
    MPI_Comm_size(MPI_COMM_WORLD, &size);   

    float grad[D];  

#pragma omp parallel sections
    {
#pragma omp section
        {
            fake_backward(grad);
            std::cout << "[Rank " << rank << "] Grad computed" << std::endl;
        }
#pragma omp section
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            fake_allreduce(grad, rank, size);
            std::cout << "[Rank " << rank << "] Grad AllReduced" << std::endl;
        }
    }

    // Finalize MPI environment
    MPI_Finalize();

    return 0;
}
