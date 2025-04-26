# proj_759
 Spring 2025 ECE 759 Project
Overlapping Gradient Computation and All-Reduce Communication for 
Scalable Deep Learning Training


 Sumukha Madodi
 Shraddha Singh
 Sahana Divakar
 Shashank M Bharadwaj



This project speeds up how computers train deep learning models by making them **work on two tasks at once** — calculating data (compute) and sharing results between GPUs (communication). Instead of waiting for one task to finish before starting the other, it **overlaps** them, like multitasking. This saves time and makes better use of hardware. The project simulates this smart multitasking on different systems using CUDA, OpenMP, and MPI techniques.