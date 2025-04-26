import matplotlib.pyplot as plt

# === Simulated Data for Scaling Behavior ===
chunks = [5, 10, 15, 20, 25, 30, 35, 40]

# Simulated total execution times (in milliseconds)
no_overlap_times = [7500, 15000, 22500, 30000, 37500, 45000, 52500, 60000]
with_overlap_times = [4200, 8300, 12500, 16600, 20800, 24900, 29000, 33100]

# === Plotting ===
plt.figure(figsize=(12,7))

# Plot both lines
plt.plot(chunks, no_overlap_times, marker='o', color='red', linewidth=2, label='No Overlap')
plt.plot(chunks, with_overlap_times, marker='o', color='green', linewidth=2, label='With Overlap')

# Labels and Title
plt.xlabel('Number of Chunks', fontsize=12)
plt.ylabel('Total Execution Time (ms)', fontsize=12)
plt.title('Execution Time Scaling: No Overlap vs With Overlap', fontsize=14)

# Grid, Legend, and Styling
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(fontsize=12)
plt.tight_layout()

# Save Plot
plt.savefig('execution_time_scaling.png')
print("Plot saved as execution_time_scaling.png")

# Display Plot
plt.show()
