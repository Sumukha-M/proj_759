#include <omp.h>
#include "compute.h"
#include "communicate.h"

int main() {
#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 0; i < 5; ++i)
                compute_gradients();
        }
#pragma omp section
        {
            for (int j = 0; j < 5; ++j)
                communicate_gradients();
        }
    }
}
