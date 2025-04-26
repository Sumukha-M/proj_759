#include <iostream>

void compute_gradients() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "[GradCompute] Layer " << i << std::endl;   // added layer number
    }
}
