from sys import stdin
from collections import deque

n, m, k = map(int, stdin.readline().split())

l = [[0 for j in range(m + 1)]] + [[0] + list(map(int, stdin.readline().split())) for i in range(n)]
v = [[-1 for i in range(m + 1)] for j in range(n + 1)]
dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]

ix, iy = 0, 0
res = []
q = deque()
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if (l[i][j] == 3):
            if (k != 0): q.append((i, j))
            v[i][j] = k
        elif (l[i][j] == 4):
            ix, iy = i, j
        elif (l[i][j] == 2):
            res.append((i, j))

while (q):
    x, y = q.popleft()
    l[x][y] = 3
    for i in range(4):
        cx, cy = x + dx[i], y + dy[i]
        if (cx <= 0 or cx > n or cy <= 0 or cy > m): continue
        if (v[cx][cy] != -1): continue
        v[cx][cy] = v[x][y] - 1
        l[cx][cy] = 3
        if (v[cx][cy] > 0):
            q.append((cx, cy))

q.append((ix, iy))
v = [[-1 for i in range(m + 1)] for j in range(n + 1)]
v[ix][iy] = 0
while (q):
    x, y = q.popleft()
    for i in range(4):
        cx, cy = x + dx[i], y + dy[i]
        if (cx <= 0 or cx > n or cy <= 0 or cy > m): continue
        if (v[cx][cy] != -1 or l[cx][cy] not in [0, 2]): continue
        v[cx][cy] = v[x][y] + 1
        q.append((cx, cy))
        if (l[cx][cy] == 2): break

ans = -1
for i in res:
    if (ans == -1 and v[i[0]][i[1]] != -1): ans = v[i[0]][i[1]]
    elif (v[i[0]][i[1]] != -1): ans = min(ans, v[i[0]][i[1]])
print(ans)