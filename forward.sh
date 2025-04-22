#!/usr/bin/env zsh
#SBATCH -p instruction
#SBATCH -J forward_cuda
#SBATCH -o logs/manual.out
#SBATCH -e logs/manual.err
#SBATCH --gres=gpu:1
#SBATCH -c 1
#SBATCH --time=0-00:10:00

# Load modules
module load gcc/11.3.0
module load nvidia/cuda/11.8

cd $SLURM_SUBMIT_DIR

# ✅ Correct Linux-based LibTorch with CUDA 11.8
if [ ! -d "libtorch" ]; then
  echo "[INFO] Downloading LibTorch (CUDA 11.8)..."
  curl -L -o libtorch.zip "https://download.pytorch.org/libtorch/cu118/libtorch-cxx11-abi-shared-with-deps-2.1.2+cu118.zip"
  unzip libtorch.zip && rm libtorch.zip
  echo "[INFO] LibTorch downloaded and extracted."
fi

# ✅ Verify header exists
if [ ! -f "libtorch/include/torch/torch.h" ]; then
  echo "[ERROR] LibTorch headers not found. Aborting."
  exit 1
fi

# Compile
echo "[INFO] Compiling project with nvcc..."
nvcc -std=c++17 \
  -I libtorch/include \
  -I libtorch/include/torch/csrc/api/include \
  -L libtorch/lib \
  -ltorch -lc10 -ltorch_cpu \
  -Xcompiler -fopenmp \
  src/main.cpp src/forward.cu \
  -o overlap_dl

# Linker path
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/libtorch/lib

# Run
if [ ! -f "./overlap_dl" ]; then
  echo "[ERROR] Executable not found. Compilation failed."
  exit 1
fi

echo "[INFO] Running CUDA forward pass..."
./overlap_dl

