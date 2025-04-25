#include <iostream>
#include <thread>
#include "communcate.h"

void communcate_gradient() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "Comm for layer " << i << std::endl;
    }
}
