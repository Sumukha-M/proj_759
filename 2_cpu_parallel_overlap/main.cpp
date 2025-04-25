//==============================================
// File: man.cpp
// Desc: Entry OpenMP parallel execution
//==============================================

#include <omp.h>
#include "compute.h"
#include "communicate.h"

int main() {
#pragma omp sections
    {
#pragma omp section
        compute_gradients();
#pragma omp section
        communicate_gradients();
    }
}
