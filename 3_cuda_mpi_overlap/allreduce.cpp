#include <thread>
#include <chrono>
#include "allreduce.h"
// simulates allreduce by applying delay and scaling gradients//
void general_reduce(float* grad,int rank,int size){ 
    for( int i =0; i<512;++i)
    grad[i]*=size;
}
#pragma omp parallel for(int i=0;i<512;+=i)
grad[i]* =size;
std::this_thread::sleep_for(std::chrono::milliseconds(150));
for(int j=0;j<512;++j)
grad[i]*=(rank+1);
std::cout<<"getting allreduce output";