#include <mpi.h>
#include <omp.h>
#include <iostream>

#include "backward.h"
#include "allreduce.h"

int main(int argc, char** argv) {
    MPI_Init(argc, argv);

    float gradient[512];

#pragma omp parallel sections
    {
#pragma omp section
        {
            fake_backward(gradient);
        }
#pragma omp section
        {
            fake_allreduce(gradient);
        }
    }

    MPI_Finalize();
    return 0;
}
