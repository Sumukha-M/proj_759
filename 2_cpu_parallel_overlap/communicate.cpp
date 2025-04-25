#include <iostream>
#include <thread>
#include "communicate.h"

void communiate_gradients() {
    for (int i = 0; i < 5; i++) {
        std::cout << "[Test] Layer " << i << std::endl;
    }
}
