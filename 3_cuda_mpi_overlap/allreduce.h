//==============================================
// File: allreduce.h
// Desc: Declaration of fake_allreduce()
// Simulates collective operation
//==============================================

#ifndef ALLREDUCE_H
#define ALLREDUCE_H

void fake_allreduce(float* grad, int rank, int size);

#endif
