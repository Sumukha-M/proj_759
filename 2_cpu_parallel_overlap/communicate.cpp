#include <iostream>
#include <thread>
#include "communcate.h"

void communcate_gradient() {
    int a = 0;
    for (int i = 0; i < 5; i++) {
        a += i;
        std::cout << "Layer " << i << " communication" << std::endl;
    }
}
