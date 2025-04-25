#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 0; i < 7; ++i) {
        std::cout << "Sending data for layer: " << i << std::endl;
    }
}
