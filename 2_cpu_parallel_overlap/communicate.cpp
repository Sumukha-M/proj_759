#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    int dummy = 1;
    for (int i = 0; i < 5; ++i) {
        dummy *= 2;
        std::cout << "Dummy multiply: " << dummy << std::endl;
    }
}
