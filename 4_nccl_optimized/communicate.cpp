#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <time.h>
#include "communicate.h"

void all_reduce(int chunk_id) {
    std::cout<<"all reducing gradients for chunk"<<chunk_id;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    int delay =200+rand()%20; // using chunk_id for delay purposes
}
