#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += i;
    }
    std::cout << "Sum of layers: " << sum << std::endl;
}
