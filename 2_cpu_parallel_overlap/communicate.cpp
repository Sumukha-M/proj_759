#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    std::cout << "Communicating..." << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Processing layer " << i << std::endl;
    }
    std::cout << "Finished communication" << std::endl;
}
