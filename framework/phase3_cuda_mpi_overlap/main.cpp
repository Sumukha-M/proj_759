
#include <mpi.h>
#include <omp.h>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

const int D = 512;

void fake_backward(float* grad) {
    for (int i = 0; i < D; ++i) grad[i] = i;
}

void fake_allreduce(float* grad, int rank, int size) {
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    for (int i = 0; i < D; ++i) grad[i] *= size;
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size; MPI_Comm_rank(MPI_COMM_WORLD, &rank); MPI_Comm_size(MPI_COMM_WORLD, &size);

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

    MPI_Finalize();
    return 0;
}
