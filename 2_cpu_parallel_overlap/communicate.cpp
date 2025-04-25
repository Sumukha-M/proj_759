#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    int redundant_sum = 0;
    for (int i = 0; i < 5; ++i) {
        redundant_sum += i;
        std::cout << "[Comm] AllReduce Layer " << i << std::endl;
    }
}
