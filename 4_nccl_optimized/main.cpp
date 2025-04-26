#include <omp.h>
#include <iostream>
#include "compute.h"
#include "communicate.h"

// Number of chunks to simulate overlapping
const int NUM_CHUNKS = 4;

int main() {
    std::cout << "=== Phase 4: Overlapping Compute & Communication Simulation ===\n";

    // For each chunk, simulate overlap using OpenMP parallel sections
    for (int i = 0; i < NUM_CHUNKS; ++i) {
#pragma omp parallel sections
        {
#pragma omp section
            {
                compute_gradients(i);
            }
#pragma omp section
            {
                if (i > 0) {  // Communicate previous chunk while computing current
                    mock_allreduce(i - 1);
                }
            }
        }
    }

    // Final communication for the last chunk
    mock_allreduce(NUM_CHUNKS - 1);

    std::cout << "[Done] Overlapping simulation complete!\n";
    return 0;
}
