#include <iostream>
#include <thread>

void communcate_gradient() {
    for (int i = 0; i < 5; i++) {
        std::cout << "[DEBUG] Working on layer " << i << std::endl;
    }
}
