
# cuda_overlap_simulation – Optimizing Compute and Communication Overlap

## 🚀 Overview
This module demonstrates how to optimize deep learning training by **overlapping gradient computation and communication**. It simulates the behavior of **CUDA Streams** and **NCCL AllReduce** using C++ threads and OpenMP to showcase how multitasking can significantly reduce total execution time in HPC environments.

The focus here is on simulating chunked gradient processing, where computation of one chunk overlaps with the communication of the previous chunk.

---

## 🎯 Objective
- Illustrate the benefits of **compute-communication overlap**.
- Simulate how frameworks like NCCL and CUDA Streams optimize distributed deep learning.
- Generate timing data to visualize performance improvements.

---

## ⚙️ How It Works
- Uses **OpenMP** and **std::thread** to mimic asynchronous compute and communication.
- Introduces **chunked gradient computation** for realistic simulation.
- Logs execution times for each chunk and total runtime.
- Outputs a `timing_data.csv` file for performance analysis and plotting.

---

## 📂 File Structure
| File                  | Description                                      |
|-----------------------|--------------------------------------------------|
| `main.cpp`            | Controls simulation flow and timing              |
| `compute.cpp`         | Simulates gradient computation with variability  |
| `communicate.cpp`     | Simulates communication delay (mock NCCL)        |
| `compute.h`           | Header for compute function                      |
| `communicate.h`       | Header for communication function                |
| `Makefile`            | Automates compilation using `nmake`              |
| `timing_data.csv`     | Generated timing data for plotting               |
| `overlap_performance_plot.py` | Plots chunk-wise execution times         |
| `execution_time_scaling_plot.py` | Plots scaling behavior                |

---

## 🖥️ How to Compile & Run
1. Open **x64 Native Tools Command Prompt**.
2. Navigate to the `cuda_overlap_simulation` directory.
3. Compile using:
   ```bash
   nmake
   ```
4. Run the simulation:
   ```bash
   overlap_sim.exe
   ```

5. Generate performance plots:
   ```bash
   python overlap_performance_plot.py
   python execution_time_scaling_plot.py
   ```

---

## ✅ Expected Output
- Console output showing chunk-wise compute and communication logs.
- A `timing_data.csv` file containing execution times.
- Two plot images:
  - `chunk_execution_times.png`
  - `execution_time_scaling.png`

---

## 🎯 What We Achieve
- Demonstrate how overlapping reduces total training time.
- Visualize performance improvements through automated plots.
- Simulate advanced HPC techniques in a Windows environment without needing GPUs.

This module highlights the core optimization strategy used in large-scale AI training — **hiding communication latency by overlapping it with computation**.
