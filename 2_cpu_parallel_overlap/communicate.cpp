#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    int fake_flag = 1;
    if (fake_flag) {
        for (int i = 0; i < 5; ++i) {
            std::cout << "[Comm] Simulating AllReduce Layer " << i << std::endl;
        }
    }
}
