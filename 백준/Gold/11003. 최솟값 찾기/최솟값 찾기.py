from sys import stdin
from collections import deque

n, l = map(int, stdin.readline().split())
ary = map(int, stdin.readline().split())
q = deque()
res = [0 for i in range(n)]
i = 0
for data in ary:
    m = i - l
    while (q and q[0][1] <= m):
        q.popleft()
    while (q and q[-1][0] > data):
        q.pop()
    q.append((data, i))
    res[i] = q[0][0]
    i += 1
print(*res)
