import random
import math
import time

random.seed(time.time())

TRIALS = 10000000

S = [300, 300, 200, 200, 100, 100]
Z = [50, 30, 20, 0, 0, 0]

mean_stack = sum(S) / len(S)
Q = [s / mean_stack for s in S]

X = [0 for _ in range(len(S))]

for i in range(TRIALS):
    P = [math.pow(random.random(), 1 / q) for q in Q]
    a = sorted(zip(P, range(len(S))), reverse=True)
    for j in range(len(X)):
        X[a[j][1]] += Z[j]

Y = [x / TRIALS for x in X]
print(Y)
