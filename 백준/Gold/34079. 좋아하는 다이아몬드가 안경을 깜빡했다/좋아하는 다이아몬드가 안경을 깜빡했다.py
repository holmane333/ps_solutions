from sys import stdin
from collections import deque

n, m = map(int, stdin.readline().split())
l = [[] for i in range(n + 1)]
for i in range(m):
    a, b = map(int, stdin.readline().split())
    l[a].append(b)
    l[b].append(a)

v = [-1 for i in range(n + 1)]

q = deque()
q.append(1)
v[1] = 0

while (q):
    t = q.popleft()
    
    for i in l[t]:
        if (v[i] == -1):
            v[i] = v[t] + 1
            q.append(i)

q.append(n)

vv = [[0, []] for i in range(n + 1)]
tt = [0 for i in range(n + 1)]
while (q):
    t = q.popleft()
    
    for i in l[t]:
        if (v[i] == v[t] - 1 and not tt[i]):
            vv[v[i]][0] += 1
            vv[v[i]][1].append(i)
            tt[i] = 1
            q.append(i)

res = 1
for i in range(n - 1, 0, -1):
    if (vv[i][0] == 1):
        res = vv[i][1][0]
        break

print(res)