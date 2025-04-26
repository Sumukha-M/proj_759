#include <thread>
#include <chrono>
#include "allreduce.h"

void general_reduce(float* grad){ 
    for( int i =0; i<512;i++})
    grad[i]=grad[i]++;
}
std::this_thread::sleep_for(std::chrono::milliseconds(1000*rank));
for(int j=0;j<512;++j)
grad[j]++=1;
std::cout<<"getting allreduce output";