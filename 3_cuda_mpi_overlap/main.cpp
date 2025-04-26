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

    float grad[D];

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 0; i < 2; ++i)
                fake_backward(grad);
            std::cout << "[Rank " << rank << "] Backward multiple passes" << std::endl;
        }
#pragma omp section
        {
            for (int j = 0; j < 2; ++j)
                fake_allreduce(grad, rank, size);
            std::cout << "[Rank " << rank << "] Communication multiple passes" << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
