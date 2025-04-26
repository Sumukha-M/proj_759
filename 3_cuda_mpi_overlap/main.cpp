#include <mpi.h>
#include <omp.h>
#include <iostream>

#include "backward.h"
#include "allreduce.h"

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    float gradient[512];

#pragma omp parallel sections
    {
#pragma omp section
        {
            fake_backward(gradient);
            std::cout << "Backward completed" << std::endl;
        }
#pragma omp section
        {
            fake_allreduce(gradient, 0, 1);
            std::cout << "AllReduce completed" << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
