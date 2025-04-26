#include "backward.h"

const int D = 512;

// Simulate backward pass (gradient computation)
void fake_backward(float* gradients) {
    for (int i = 0; i < D; ++i)
        gradients[i] = i;
}
