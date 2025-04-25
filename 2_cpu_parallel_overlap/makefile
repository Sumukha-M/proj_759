# NMake Makefile for Phase 2: OpenMP Overlap Modular Project

# Compiler
CC = cl

# Compiler Flags
CFLAGS = /openmp

# Source Files
SRC = main.cpp compute.cpp communicate.cpp

# Output Executable
TARGET = openmp_overlap_modular.exe

# Default Target
all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) /Fe:$(TARGET)

# Clean Target
clean:
	del $(TARGET)
