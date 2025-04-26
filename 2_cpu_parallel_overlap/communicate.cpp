#include <iostream>
#include <thread>  // added thread

void compute_gradients() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "[GradCompute] Layer " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // wrong sleep (100ms instead of 200ms), and missing chrono include
    }
}
