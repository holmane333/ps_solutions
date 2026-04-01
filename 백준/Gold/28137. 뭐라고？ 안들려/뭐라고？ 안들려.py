import sys

n, k = map(int, sys.stdin.readline().split())

d = dict()
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    b = y - k * x
    if (b in d): d[b] += 1
    else: d[b] = 1

res = 0
for i in d.values():
    res += i * (i - 1)

print(res)
