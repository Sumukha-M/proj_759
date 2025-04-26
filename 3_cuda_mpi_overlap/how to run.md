

nmake clean
nmake
mpi_overlap_modular.exe
mpiexec -n 2 mpi_overlap_modular.exe

nmake clean