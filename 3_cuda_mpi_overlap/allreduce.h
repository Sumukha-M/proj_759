//==============================================
// File: allreduce.h
// Description: Declaration of fake_allreduce() function.
// Simulates collective MPI operation with fake delay.
//==============================================

#ifndef ALLREDUCE_H
#define ALLREDUCE_H

void fake_allreduce(float* grad, int rank, int size);

#endif
