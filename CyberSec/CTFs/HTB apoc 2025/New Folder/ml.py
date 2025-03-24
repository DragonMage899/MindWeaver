import torch
model = torch.load("eldorian_artifact.pth")

print(model)
print(model.keys())
print(model['hidden.weight'])

weights = model['hidden.weight']
diagonal_values = weights.diagonal()

flag = ''

for i in range(len(diagonal_values)):
    val = diagonal_values[i].item()
    flag += chr(int(val))

print(flag)