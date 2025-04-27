# # NMake Makefile for Phase 2: OpenMP Overlap Modular Project

# # Compiler
# CC = cl

# # Compiler Flags
# CFLAGS = /openmp

# # Source Files
# SRC = main.cpp compute.cpp communicate.cpp

# # Output Executable
# TARGET = openmp_overlap_modular.exe

# # Default Target
# all: $(TARGET)

# $(TARGET):
# 	$(CC) $(CFLAGS) $(SRC) /Fe:$(TARGET)

# # Clean Target
# clean:
# 	del $(TARGET)





# NMake Makefile for cpu_parallel_overlap: Auto-Build, Run, and Log Timings


# Declare phony targets to avoid conflicts
.PHONY: all clean run_timings

# Compiler and Flags
CC = cl
CFLAGS = /openmp

# Common Source Files
SRC_COMMON = compute.cpp communicate.cpp

# Executable Names
OVERLAP_TARGET = cpu_overlap.exe
SEQUENTIAL_TARGET = cpu_sequential.exe

# Default Target: Build Both and Run Timings
all: $(OVERLAP_TARGET) $(SEQUENTIAL_TARGET) run_timings

# Build Overlapped Execution
$(OVERLAP_TARGET):
	$(CC) $(CFLAGS) main_overlap.cpp $(SRC_COMMON) /Fe:$(OVERLAP_TARGET)

# Build Sequential Execution
$(SEQUENTIAL_TARGET):
	$(CC) main_sequential.cpp $(SRC_COMMON) /Fe:$(SEQUENTIAL_TARGET)

# Run Both Executables and Log Timings
run_timings:
	@echo Running Sequential Version... > timing_results.txt
	@$(SEQUENTIAL_TARGET) >> timing_results.txt
	@echo Running Overlap Version... >> timing_results.txt
	@$(OVERLAP_TARGET) >> timing_results.txt
	@echo Timings logged in timing_results.txt

# Clean Target
clean:
	del $(OVERLAP_TARGET) $(SEQUENTIAL_TARGET) timing_results.txt
