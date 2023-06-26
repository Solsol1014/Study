import numpy as np

t = int(input())

for i in range(t):
    inputsstr = input()
    inputs = inputsstr.split()
    for j in inputs:
        inputs.insert(0, float(inputs.pop()))
    

#할수는 있는데 와 미친 너무 개노가다 아니냐고 이거,,,, 노타빌리티에다가 대충 계산하다 말았음 포기포기