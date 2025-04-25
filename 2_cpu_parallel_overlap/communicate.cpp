#include <iostream>
#include <thread>
#include "communicate.h"

void communicate_gradients() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Layer #" << i << " is being processed." << std::endl;
    }
}
void communicate_weights() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Layer #" << i << " is being processed." << std::endl;
    }
}
void communicate() {
    std::thread t1(communicate_gradients);
    std::thread t2(communicate_weights);

    t1.join();
    t2.join();
}