#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "communicate.h" // including necessary headers

void mock_allreduce(int chunk_id) {
    int delay =200+rand()%30;
    std::cout<<"all reducing gradients for chunk"<<chunk_id<<"..\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    // using chunk_id for delay purposes
}
