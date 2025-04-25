#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "[COMM] Working on layer " << i << std::endl;
    }
}
void communicate_weights() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "[COMM] Working on layer " << i << std::endl;
    }
}