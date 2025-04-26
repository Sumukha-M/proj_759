
# cuda_mpi_overlap – Simulating Distributed Compute and Communication Overlap

## 🚀 Overview
This module simulates a **distributed deep learning environment** by combining **CUDA**, **MPI**, and **OpenMP**. It demonstrates how gradient computation and communication (like AllReduce) can be overlapped to improve efficiency in multi-GPU or multi-node setups.

While real GPU-to-GPU communication would use libraries like NCCL, this implementation uses MPI and threading to **mock communication overhead** and highlight the challenges in distributed training.

---

## 🎯 Objective
- Simulate a distributed compute + communication workflow.
- Expose the impact of **communication bottlenecks** in parallel deep learning.
- Demonstrate how overlapping techniques can mitigate delays in HPC environments.

---

## ⚙️ How It Works
- Uses **CUDA** to simulate gradient computation tasks.
- Uses **MPI** to mimic inter-process communication (mocked AllReduce behavior).
- **OpenMP** is employed to overlap compute and communication within each process.
- Focuses on conceptually showing how distributed systems handle large-scale training.

---

## 📂 File Structure
| File              | Description                                      |
|-------------------|--------------------------------------------------|
| `main.cpp`        | Initializes MPI, manages parallel sections       |
| `backward.cpp`    | Simulates CUDA-based gradient computation        |
| `allreduce.cpp`   | Mocks MPI AllReduce communication                |
| `backward.h`      | Header for compute function                      |
| `allreduce.h`     | Header for communication function                |
| `Makefile`        | Automates compilation using `nmake`              |

---

## 🖥️ How to Compile & Run
1. Open **x64 Native Tools Command Prompt**.
2. Ensure MPI is installed and configured.
3. Navigate to the `cuda_mpi_overlap` directory.
4. Compile using:
   ```bash
   nmake
   ```
5. Run with multiple processes (simulated distributed environment):
   ```bash
   mpiexec -n 2 cuda_mpi_overlap.exe
   ```

---

## ✅ Expected Output
You will see messages indicating gradient computation and communication happening in parallel across processes:

```
[Rank 0] Grad computed
[Rank 0] Grad AllReduced
[Rank 1] Grad computed
[Rank 1] Grad AllReduced
...
```

---

## 🎯 What We Achieve
- Understand the role of **communication overhead** in distributed deep learning.
- Demonstrate how overlapping compute and communication reduces idle time.
- Prepare for advanced HPC optimizations, such as NCCL and CUDA Streams, by simulating real-world challenges.

This module emphasizes why efficient communication strategies are critical in large-scale AI training workloads.
