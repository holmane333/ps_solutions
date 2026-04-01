from sys import stdin
from collections import deque

n, m, k = map(int, stdin.readline().split())
inf = int(1e9)
l = [['#' for i in range(m + 1)]] + [['#'] + list(stdin.readline().rstrip()) for i in range(n)]
sx, sy, rx, ry = map(int, stdin.readline().split())
dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
v = [[inf for i in range(m + 2)] for j in range(n + 2)]
dq = deque()
dq.append((sx, sy))
v[sx][sy] = 0
while (dq):
    x, y = dq.popleft()
    if (x == rx and y == ry): break
    for i in range(4):
        for j in range(1, k + 1):
            cx, cy = x + dx[i] * j, y + dy[i] * j
            if (cx <= 0 or cx > n or cy <= 0 or cy > m): continue
            if (l[cx][cy] == '#'): break
            if (v[cx][cy] <= v[x][y]): break
            if (v[cx][cy] == inf):
                v[cx][cy] = v[x][y] + 1
                dq.append((cx, cy))

if (v[rx][ry] == inf): print(-1)
else: print(v[rx][ry])