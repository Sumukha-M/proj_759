//==============================================
// File: backward.cpp
// Description: Implements fake_backward function.
// This function simulates gradient computation by
// initializing each element of the gradient array.
//==============================================

#include "backward.h"

// Define the gradient size (must match main.cpp)
const int D = 512;

// Simulate backward pass (gradient computation)
// Each element of grad[] is set to its index value.
void fake_backward(float* grad) {
    for (int i = 0; i < D; ++i) {
        grad[i] = i;  // Dummy computation to simulate gradient generation
    }
}
