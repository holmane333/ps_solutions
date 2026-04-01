import sys

n = int(sys.stdin.readline())
l = []

# a - f, b - d, c - e

for i in range(n):
    a, b, c, d, e, f = map(int, sys.stdin.readline().split())
    l.append([0, f, d, e, b, c, a])
    l[i][a] = f
    l[i][b] = d
    l[i][c] = e
    l[i][d] = b
    l[i][e] = c
    l[i][f] = a

res = 0
res_max = 0
for i in range(1, 7):
    t = i
    for j in range(n):
        trans_t = l[j][t]
        for k in range(6, 0, -1):
            if (t == k or trans_t == k):
                continue
            res += k
            break
        t = trans_t
    res_max = max(res_max, res)
    res = 0

print(res_max)
