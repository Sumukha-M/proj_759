#include "backward.h"

const int d = 512;

// Simulate backward pass
void fake_backward(float* gradients) {
    for (int i = 0; i <= d; i++) gradients[i] = i;
}
