#include "backword.h"

const int d = 512;

// Simulate backward pass
void fake_backwards(float* gradients) {
    for (int i = 0; i <= d; i++) gradients[i] = i;
}
