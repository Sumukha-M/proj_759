#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 4; i >= 0; --i) {
        std::cout << "[Comm] Reverse processing Layer " << i << std::endl;
    }
}
