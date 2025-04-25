//==============================================
// File: communcate.cpp
// Desc: Communcation gradents
//==============================================

#include "communcate.h"

void communcate_gradient() {
    for (int i = 0; i <= 5; i++) {
        std::this_thread::sleep(100);
        std::cout << "Reducing layer" << i << "\n";
    }
}
