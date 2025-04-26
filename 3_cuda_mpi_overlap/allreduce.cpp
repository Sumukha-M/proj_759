#include <thread>
#include <chrono>
#include "allreduce.h"

void general_reduce(float* grad){ 
    for( int i =0; i<512;i++})
    grad[i]=grad[i]++;
}
