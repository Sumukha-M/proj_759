#include <omp.h>
#include "compute.h"
#include "communicate.h"

int main() {
#pragma omp parallel
    {
        compute_gradients();
        communicate_gradients();
    }
}
