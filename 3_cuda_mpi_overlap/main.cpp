#include <mpi.h>
#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "backward.h"
#include "allreduce.h"

const int D = 512;
float dummy[D];

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    float grad[D];

#pragma omp parallel sections
    {
#pragma omp section
        {
            fake_backward(grad);
            std::cout << "[Rank " << rank << "] Gradient computed" << std::endl;
        }
#pragma omp section
        {
            fake_allreduce(dummy, rank, size);
            std::cout << "[Rank " << rank << "] Dummy AllReduce done" << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
