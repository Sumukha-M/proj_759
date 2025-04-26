#include <omp.h>
#include <iostream>
#include <chrono>
#include "compute.h"
#include "communicate.h"

const int NUM_CHUNKS = 4;

int main() {
    std::cout << "=== Phase 4: Overlapping Compute & Communication Simulation ===\n";

    auto total_start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_CHUNKS; ++i) {
        auto chunk_start = std::chrono::high_resolution_clock::now();

#pragma omp parallel sections
        {
#pragma omp section
            {
                compute_gradients(i);
            }
#pragma omp section
            {
                if (i > 0) {
                    mock_allreduce(i - 1);
                }
            }
        }

        auto chunk_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> chunk_time = chunk_end - chunk_start;
        std::cout << "[Chunk " << i << "] Time: " << chunk_time.count() << " ms\n";
    }

    mock_allreduce(NUM_CHUNKS - 1);

    auto total_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> total_time = total_end - total_start;

    std::cout << "[Total Execution Time]: " << total_time.count() << " ms\n";
    return 0;
}
