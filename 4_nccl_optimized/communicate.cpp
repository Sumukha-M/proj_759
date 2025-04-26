#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <time.h>
#include "communicate.h"

void all_reduce(int chunk_id) {
    std::cout<<"starting all reduce \n";
    std::this_thread::sleep_for(std::chrono::millisecond(10000));
    int delay =200+rand()%20;
}
