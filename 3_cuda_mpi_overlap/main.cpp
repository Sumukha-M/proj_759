#include <mpi.h>
#include <omp.h>
#include <iostream>

#include "backward.h"
#include "allreduce.h"

const int D = 512;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    float grad[D];

#pragma omp parallel sections
    {
#pragma omp section
        {
            fake_backward(grad);
            std::cout << "Backward completed" << std::endl;
        }
#pragma omp section
        {
            fake_allreduce(grad, 0, 1);
            std::cout << "AllReduce completed" << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
