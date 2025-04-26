#include <omp.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "compute.h"
#include "communicate.h"

const int NUM_CHUNKS = 20;   // Increased number of chunks

int main() {
    std::srand(std::time(nullptr));  // Seed for randomness

    std::ofstream logfile("timing_data.csv");
    logfile << "Chunk,ChunkTime_ms\n";   // CSV header

    std::cout << "=== Overlapping Compute & Communication Simulation ===\n";

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

        logfile << i << "," << chunk_time.count() << "\n";
    }

    mock_allreduce(NUM_CHUNKS - 1);

    auto total_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> total_time = total_end - total_start;

    std::cout << "[Total Execution Time]: " << total_time.count() << " ms\n";
    logfile << "Total," << total_time.count() << "\n";

    logfile.close();
    return 0;
}
