#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 1; i <= 5; ++i) {
        if (i % 2 == 0) {
            std::cout << "Even Layer: " << i << std::endl;
        } else {
            std::cout << "Odd Layer: " << i << std::endl;
        }
    }
}
