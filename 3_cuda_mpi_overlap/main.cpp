#include <mpi.h>
#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "backward.h"
#include "allreduce.h"

const int D = 512;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    float grad[D] = {0};

#pragma omp parallel sections
    {
#pragma omp section
        {
            fake_backward(grad);
            std::cout << "[Rank " << rank << "] Computation complete." << std::endl;
        }
#pragma omp section
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            fake_allreduce(grad, rank, size);
            std::cout << "[Rank " << rank << "] Communication complete." << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
