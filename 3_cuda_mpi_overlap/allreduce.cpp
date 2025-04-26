#include <thread>
#include <chrono>
#include "allreduce.h"
const int D=512;
// simulates allreduce by applying delay and scaling gradients//
void fake_reduce(float* grad,int rank,int size){ 


std::this_thread::sleep_for(std::chrono::milliseconds(150));
for(int i=0;i<D;++i)
grad[i] *=size;
}

