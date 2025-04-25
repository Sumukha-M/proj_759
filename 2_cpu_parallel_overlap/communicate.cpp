#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 5; i > 0; --i) {
        std::cout << "Layer countdown: " << i << std::endl;
    }
}
