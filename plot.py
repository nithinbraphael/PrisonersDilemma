import sys
import matplotlib.pyplot as plt

x, y = [], []

for line in sys.stdin:
    a, b = map(int, line.split())
    x.append(a)
    y.append(b)

plt.plot(x, y)
plt.show()