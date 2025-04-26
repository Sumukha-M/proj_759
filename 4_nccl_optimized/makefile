# NMake Makefile for Phase 4 Overlap Simulation (Windows)

CC = cl
CFLAGS = /openmp
SRC = main.cpp compute.cpp communicate.cpp
TARGET = overlap_sim.exe

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) /Fe:$(TARGET)

clean:
	del $(TARGET)
