
# matrix_train_cuda: CUDA Baseline – Deep Learning Training Simulation

## 🚀 Overview
This phase implements a **basic deep learning training loop** using **CUDA** on a single GPU. It simulates the core operations involved in training a neural network:

- **Forward Pass**  ➔ Matrix Multiplication  
- **Backward Pass** ➔ Gradient Computation  
- **SGD Update**    ➔ Weight Adjustment  

The goal of this phase is to establish a **baseline** for compute performance, focusing purely on GPU computation **without considering any communication overhead**.

---

## 🎯 Objective
- Demonstrate how deep learning workloads rely heavily on matrix operations.
- Highlight that on a single GPU, the **compute workload** dominates.
- Set the foundation to understand future challenges when scaling to multiple GPUs (which will introduce communication delays).

---

## ⚙️ How It Works
- Written in **CUDA C++**.
- Uses custom CUDA kernels to:
  - Perform matrix multiplication for forward and backward passes.
  - Apply stochastic gradient descent (SGD) for weight updates.
- Executes **one iteration** of training on dummy data.

---

## 📂 File Structure
| File         | Description                               |
|--------------|-------------------------------------------|
| `main.cu`    | Entry point, memory management, execution |
| `forward.cu` | CUDA kernel for forward pass              |
| `backward.cu`| CUDA kernel for backward pass             |
| `update.cu`  | CUDA kernel for SGD weight update         |
| `Makefile`   | Automates compilation using `nmake`       |

---

## 🖥️ How to Compile & Run
1. Open **x64 Native Tools Command Prompt**.
2. Navigate to the matrix_train_cuda directory.
3. Compile using the Makefile:
   ```bash
   nmake
   ```
4. Run the executable:
   ```bash
   cuda_baseline.exe
   ```

---

## ✅ Expected Output
```
One training iteration complete.
```

---

## 🎯 What We Achieve in matrix_train_cuda
- Establish a **compute-only baseline** for deep learning training.
- Understand the performance characteristics of GPU-based matrix operations.
- Realize that while this runs efficiently on a single GPU, scaling this approach to multiple GPUs in later phases will expose new challenges — particularly around **communication overhead**.

This phase is the **starting point** for optimizing deep learning workloads in HPC environments.
