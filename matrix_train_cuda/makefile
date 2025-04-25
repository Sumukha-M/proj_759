# Microsoft NMake Makefile for CUDA Project

# Variables
NVCC = nvcc
SRC = main.cu forward.cu backward.cu update.cu
TARGET = cuda_dnn_modular.exe

# Default target
all: $(TARGET)

$(TARGET):
	$(NVCC) $(SRC) -o $(TARGET)

clean:
	del $(TARGET)
