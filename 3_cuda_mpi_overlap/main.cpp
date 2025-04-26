#include <mpi.h>
#include <omp.h>
#include <iostream>

int main(int argc, char** argv) {  // Fix: change * to **
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    #pragma omp parallel sections  // Syntax missing `{`
        #pragma omp section
            std::cout << "[Rank " << rank << "] Doing computation\n";
        
        #pragma omp section
            std::cout << "[Rank " << rank << "] Doing communication\n";

    MPI_Finalize();
    return 0;
}
