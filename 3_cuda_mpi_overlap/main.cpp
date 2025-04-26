#include <mpi.h>
#include <omp.h>

#include "backword.h"
#include "allreduces.h"

int main(int argc, char** argv) {
    MPI_Init(argc, argv);

    float gradient[512];

#pragma omp parallel
    {
        fake_backward(gradient);
        fake_allreduces(gradient);
    }

    MPI_Finalize();
    return 0;
}
