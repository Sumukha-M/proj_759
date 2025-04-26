# NMake Makefile for Phase 3: CUDA-MPI-OpenMP Overlap Modular Project

# Compiler
CC = cl

# Compiler Flags
CFLAGS = /openmp

# MPI Include and Lib Paths (Update if installed elsewhere)
MPI_INC = "C:\Program Files (x86)\Microsoft SDKs\MPI\Include"
MPI_LIB = "C:\Program Files (x86)\Microsoft SDKs\MPI\Lib\x64"

# Source Files
SRC = main.cpp backward.cpp allreduce.cpp

# Output Executable
TARGET = mpi_overlap_modular.exe

# Default Target
all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) /I$(MPI_INC) /link /LIBPATH:$(MPI_LIB) msmpi.lib /out:$(TARGET)

# Clean Target
clean:
	del $(TARGET)
