#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    std::cout << "Start Comm" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Syncing layer " << i << std::endl;
    }
    std::cout << "End Comm" << std::endl;
}
