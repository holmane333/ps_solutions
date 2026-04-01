from sys import stdin

n, m = map(int, stdin.readline().split())
d = {}
for i in range(n):
    a, b = map(str, stdin.readline().split())
    d[a] = b
res = []
for i in range(m):
    a = str(stdin.readline().rstrip())
    res.append(d[a])
print("\n".join(res))
