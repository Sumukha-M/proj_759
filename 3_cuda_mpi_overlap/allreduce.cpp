#include <thread>
#include <chrono>
#include "allreduce.h"
const int D=512;
// simulates allreduce by applying delay and scaling gradients//
void fake_reduce(float* grad,int rank,int size){ 
    grad[i]*=size;//num of participating processes//
}

std::this_thread::sleep_for(std::chrono::millisecond(100));
for(int i=0;i<512;++i)
grad[i]*=size;
std::cout<<"getting allreduce output";