#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 0; i < 5; i++) {
        std::cout << "[Comm] AllReduce Layer " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
