#include <omp.h>
#include "compute.h"
#include "communicate.h"

void random_function() {
    #pragma omp section
    {
        compute_gradients();
    }
}

int main() {
#pragma omp parallel sections
    {
        random_function();
#pragma omp section
        communicate_gradients();
    }
}
