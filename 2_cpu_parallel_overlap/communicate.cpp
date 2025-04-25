#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    int counter = 0;
    for (int i = 0; i < 5; ++i) {
        counter += i;
        std::cout << "Working on " << i << std::endl;
    }
    std::cout << "Final counter: " << counter << std::endl;
}
