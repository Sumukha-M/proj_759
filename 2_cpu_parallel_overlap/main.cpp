#include <omp.h>
#include "compute.h"
#include "communicate.h"

int main() {
#pragma omp parallel sections
    {
#pragma omp section
        {
            compute_gradients();
        }
#pragma omp section
        {
            communicate_gradients();
        }
#pragma omp section
        {
            communicate_gradients();
        }
    }
}
