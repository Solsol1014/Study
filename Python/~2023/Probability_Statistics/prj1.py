import random
import matplotlib.pyplot as plt

def estimate_pi(n):
    num_points_circle = 0
    for i in range(n):
        x = random.uniform(0, 1)
        y = random.uniform(0, 1)
        checkCircleC = (x - 1/2)**2 + (y - 1/2)**2
        if checkCircleC <= 1/4:
            num_points_circle += 1
    return 4 * num_points_circle / n

ns = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
estimates = [estimate_pi(n) for n in ns]

plt.plot(ns, estimates)
plt.show()
