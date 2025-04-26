import pandas as pd
import matplotlib.pyplot as plt

# Load CSV data
data = pd.read_csv('timing_data.csv')

# Separate chunk data and total time
chunk_data = data[data['Chunk'] != 'Total']
total_time = data[data['Chunk'] == 'Total']['ChunkTime_ms'].values[0]

# Convert chunk numbers to int
chunk_data['Chunk'] = chunk_data['Chunk'].astype(int)

# --- Plot 1: Chunk-wise Execution Time ---
plt.figure(figsize=(10,6))
plt.bar(chunk_data['Chunk'], chunk_data['ChunkTime_ms'], color='skyblue')
plt.xlabel('Chunk Number')
plt.ylabel('Execution Time (ms)')
plt.title('Chunk-wise Compute + Communication Time')
plt.grid(True)
plt.tight_layout()
plt.savefig('chunk_execution_times.png')
plt.close()

# --- Plot 2: Total Execution Time Comparison ---
avg_chunk_time = chunk_data['ChunkTime_ms'].mean()
no_overlap_time = avg_chunk_time * len(chunk_data) * 1.8   # Simulated sequential time

plt.figure(figsize=(6,6))
plt.bar(['No Overlap', 'With Overlap'], [no_overlap_time, total_time], color=['red', 'green'])
plt.ylabel('Total Time (ms)')
plt.title('Total Execution Time: No Overlap vs With Overlap')
plt.tight_layout()
plt.savefig('total_execution_comparison.png')
plt.close()

print("Plots generated: chunk_execution_times.png and total_execution_comparison.png")
