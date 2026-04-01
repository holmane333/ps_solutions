from sys import stdin
import math

n, r = map(int, stdin.readline().split())
l = []
for i in range(n):
    l.append(int(stdin.readline()))

res = math.comb(n, 3)
idx = -n + 1
for i in range(n):
    while ((l[i] - l[idx]) % 360000 > 180000):
        idx += 1
    res -= math.comb(i - idx, 2)

print(max(res, 0))

