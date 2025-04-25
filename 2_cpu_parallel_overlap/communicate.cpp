#include <thread>
#include <iostream>
#include "communcate.h"

void communcate_gradient() {
    for (int i = 0; i < 6; i++) {
        std::cout << "AllReduce layer: " << i << "\n";
    }
}
