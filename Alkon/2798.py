#2798

n = int(input())
m = int(input())
ns = []

for i in range(n):
    ns.append(int(input()))

max = 0

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            if max<(ns[i]+ns[j]+ns[k]) and ns[i]+ns[j]+ns[k]<=m:
                max = ns[i]+ns[j]+ns[k]

print(max)
