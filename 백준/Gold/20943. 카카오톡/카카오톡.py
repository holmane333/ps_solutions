from sys import stdin

n = int(stdin.readline())
d = dict()
d[float('inf')] = 0
for i in range(n):
    a, b, c = map(int, stdin.readline().split())
    if (a == 0):
        d[float('inf')] += 1
        continue
    if (b/a not in d):
        d[b/a] = 0
    d[b/a] += 1

res = n * (n - 1) // 2
for i, v in d.items():
    res -= v * (v - 1) // 2
print(res)