import random
import math
import time
import matplotlib.pyplot as plt

random.seed(time.time())

TRIALS = 100000

q = 2

X = []

for t in range(TRIALS):
    x = math.pow(random.random(), 1 / q)
    X.append(x)

bins = 25
plt.hist(X)  # bins=[i / bins for i in range(bins)]
plt.show()
