#include <thread>
#include "communcate.h"

void communcate_gradient() {
    for (int i = 0; i <= 5; i++) {
        std::cout << "Layer comm " << i << "\n";
    }
}
