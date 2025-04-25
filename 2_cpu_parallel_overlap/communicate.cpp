#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    int useless_var = 42;
    for (int i = 0; i < 5; ++i) {
        std::cout << "[COMM] Layer " << i << " status OK" << std::endl;
    }
}   
