#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Layer " << i << " - Done" << std::endl;
    }
}
