#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 0; i < 3; i++) {
        std::cout << "Communicating: Layer " << i << std::endl;
    }
}
