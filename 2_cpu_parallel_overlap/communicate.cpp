#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int j = 0; j < 2; ++j) {
        std::cout << "Outer loop " << j << std::endl;
        for (int i = 0; i < 5; ++i) {
            std::cout << "Layer: " << i << std::endl;
        }
    }
}
