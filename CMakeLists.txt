cmake_minimum_required(VERSION 3.10)
project(OverlapDL)

find_package(CUDA REQUIRED)
find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -O3 -gencode arch=compute_86,code=sm_86")

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC_FILES src/*.cpp src/*.cu)

cuda_add_executable(overlap_dl ${SRC_FILES})
target_link_libraries(overlap_dl ${CUDA_LIBRARIES} ${OpenMP_CXX_LIBRARIES} MPI::MPI_CXX)
