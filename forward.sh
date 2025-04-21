#!/bin/bash
#SBATCH --job-name=forward_test
#SBATCH --output=logs/forward_%j.out
#SBATCH --error=logs/forward_%j.err
#SBATCH --partition=gpu
#SBATCH --gres=gpu:1
#SBATCH --time=00:10:00
#SBATCH --cpus-per-task=4

# Load modules
module load gcc
module load cuda/12.0
module load libtorch
module load cmake

# Navigate to project
cd $SLURM_SUBMIT_DIR

# Clean & build
rm -rf build
mkdir build && cd build
cmake ..
make

./overlap_dl
