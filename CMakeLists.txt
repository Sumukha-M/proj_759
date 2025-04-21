cmake_minimum_required(VERSION 3.10)
project(OverlapDL)

# Path to LibTorch (make sure this matches your folder structure)
set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/libtorch")

# Path to CUDA Toolkit (update if you installed it elsewhere)
set(CUDA_TOOLKIT_ROOT_DIR "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.6")

# Fix for missing CUDA::nvToolsExt in Windows
set(CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES "${CUDA_TOOLKIT_ROOT_DIR}/extras/nvtx/lib/x64")
set(CMAKE_CUDA_IMPLICIT_INCLUDE_DIRECTORIES "${CUDA_TOOLKIT_ROOT_DIR}/extras/nvtx/include")

# Find packages
find_package(CUDA REQUIRED)
find_package(OpenMP REQUIRED)
# find_package(MPI REQUIRED)   # Keep commented for now
find_package(Torch REQUIRED)

# Project settings
set(CMAKE_CXX_STANDARD 17)
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -O3 -gencode arch=compute_86,code=sm_86")

# Include header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
file(GLOB SRC_FILES src/*.cpp src/*.cu)

# CUDA executable
cuda_add_executable(overlap_dl ${SRC_FILES})

# Link with Torch, CUDA, and OpenMP
target_link_libraries(overlap_dl 
    ${CUDA_LIBRARIES} 
    ${OpenMP_CXX_LIBRARIES} 
    "${TORCH_LIBRARIES}"
)

# Set C++ standard
set_property(TARGET overlap_dl PROPERTY CXX_STANDARD 17)

# Optional debug print
message(STATUS "TORCH LIBRARIES: ${TORCH_LIBRARIES}")
