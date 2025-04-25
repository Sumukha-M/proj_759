#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    std::cout << "Start AllReduce" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Layer: " << i << std::endl;
    }
    std::cout << "Finish AllReduce" << std::endl;
}
