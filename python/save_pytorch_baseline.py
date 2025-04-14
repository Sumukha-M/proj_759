# save_pytorch_baseline.py

import torch
import torch.nn as nn
import os

current_dir = os.path.dirname(os.path.abspath(__file__))
data_dir = os.path.join(current_dir, "data")
os.makedirs(data_dir, exist_ok=True)


# Set device and seed
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
torch.manual_seed(42)

# Define the MLP model
model = nn.Sequential(
    nn.Linear(1024, 512), nn.ReLU(), nn.Linear(512, 256), nn.ReLU(), nn.Linear(256, 10)
).to(device)

# Dummy input and target
x = torch.randn(64, 1024, device=device)  # Batch of 64
target = torch.randint(0, 10, (64,), device=device)

# Forward pass
out = model(x)
criterion = nn.CrossEntropyLoss()
loss = criterion(out, target)

# Backward pass
loss.backward()

# Save everything
# Save all tensors in a single dictionary
save_dict = {"input": x, "target": target, "output": out, "loss": loss}

# Save model weights and gradients
for i, layer in enumerate(model):
    if isinstance(layer, nn.Linear):
        save_dict[f"layer{i}_weight"] = layer.weight.data
        save_dict[f"layer{i}_bias"] = layer.bias.data
        save_dict[f"layer{i}_weight_grad"] = layer.weight.grad
        save_dict[f"layer{i}_bias_grad"] = layer.bias.grad

# Save everything to one file
torch.save(save_dict, os.path.join(data_dir, "baseline.pt"))
