from sys import stdin

n, m = map(int, stdin.readline().split())

res = 0
min_v = 100000000007
for i in range(n):
    l = list(map(int, stdin.readline().split()))
    for j in range(m):
        res += l[j]
        min_v = min(min_v, l[j])
res -= min_v
print(res)