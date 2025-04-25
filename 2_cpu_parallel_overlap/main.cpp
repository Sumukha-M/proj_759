//==============================================
// File: main.cpp
// Description: Entry point for OpenMP parallel execution.
// Runs compute_gradients and communicate_gradients in parallel sections.
//==============================================

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
    }
    return 0;
}
