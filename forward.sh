#!/usr/bin/env zsh
#SBATCH -p instruction
#SBATCH -J forward_cuda
#SBATCH -o logs/manual_%j.out
#SBATCH -e logs/manual_%j.err
#SBATCH --gres=gpu:1
#SBATCH -c 1
#SBATCH --time=0-00:10:00

# Load required modules
module load gcc/11.3.0
module load nvidia/cuda/12.0

# Navigate to submission directory
cd $SLURM_SUBMIT_DIR

# Download LibTorch if not present
if [ ! -d "libtorch" ]; then
  echo "[INFO] Downloading LibTorch (CUDA 12.0)..."
  wget https://download.pytorch.org/libtorch/cu120/libtorch-cxx11-abi-shared-with-deps-2.1.2%2Bcu120.zip -O libtorch.zip
  unzip libtorch.zip && rm libtorch.zip
  echo "[INFO] LibTorch downloaded and extracted."
fi

# Compile CUDA + LibTorch code manually
echo "[INFO] Compiling project with nvcc..."
nvcc -std=c++17 \
  -I libtorch/include \
  -I libtorch/include/torch/csrc/api/include \
  -L libtorch/lib \
  -ltorch -lc10 -ltorch_cpu \
  -Xcompiler -fopenmp \
  src/main.cpp src/forward.cu \
  -o overlap_dl

# Set runtime path for shared libs
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/libtorch/lib

# Run the program
echo "[INFO] Running CUDA forward pass..."
./overlap_dl

