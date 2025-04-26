# cpu_parallel_overlap – Simulating Overlapping Compute and Communication on CPU

## 🚀 Overview
This module demonstrates how to **overlap computation and communication tasks** using CPU parallelism. It uses **OpenMP** to run two independent tasks — gradient computation and simulated communication — concurrently. This simulates how deep learning frameworks can optimize performance by multitasking, even without GPUs.

---

## 🎯 Objective
- Introduce the concept of **overlapping compute and communication**.
- Showcase how parallel execution on CPUs can reduce idle time.
- Build foundational understanding before applying these techniques in GPU or distributed environments.

---

## ⚙️ How It Works
- Implemented in **C++** with **OpenMP** for parallel sections.
- Two core functions:
  - `compute_gradients()` simulates gradient calculations.
  - `communicate_gradients()` simulates communication delays (like AllReduce).
- Both functions run **simultaneously** to demonstrate time-saving via parallelism.

---

## 📂 File Structure
| File              | Description                                      |
|-------------------|--------------------------------------------------|
| `main.cpp`        | Controls parallel execution using OpenMP         |
| `compute.cpp`     | Simulates gradient computation                   |
| `communicate.cpp` | Simulates communication (e.g., AllReduce)        |
| `compute.h`       | Header for compute function                      |
| `communicate.h`   | Header for communication function                |
| `Makefile`        | Automates compilation using `nmake`              |

---

## 🖥️ How to Compile & Run
1. Open **x64 Native Tools Command Prompt**.
2. Navigate to the `cpu_parallel_overlap` directory.
3. Compile using:
   ```bash
   nmake
