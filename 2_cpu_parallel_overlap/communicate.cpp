#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    int x = 0;
    for (int i = 0; i < 5; ++i) {
        x = i * 2;
        std::cout << "Layer multiplied " << x << std::endl;
    }
}
