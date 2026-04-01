import sys;input=lambda:sys.stdin.readline().rstrip()
import heapq

N, M = map(int, input().split())
l = [list(input()) for i in range(N)]

S, F = (0, 0), (0, 0)
for i in range(N):
    for j in range(M):
        if (l[i][j] == 'S'):
            S = (i, j)
        if (l[i][j] == 'F'):
            F = (i, j)

v = [[(int(1e9), int(1e9)) for i in range(M)] for j in range(N)]
che = [[0 for i in range(M)] for j in range(N)]
hq = [(0, 0, S[0], S[1])]
v[S[0]][S[1]] = (0, 0)
dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
while (hq):
    v0, v1, x, y = heapq.heappop(hq)
    # print(v0, v1, x, y)
    if (che[x][y] == 1): continue
    che[x][y] = 1
    for i in range(4):
        cx, cy = x + dx[i], y + dy[i]
        if (cx < 0 or cx >= N or cy < 0 or cy >= M): continue
        if (che[cx][cy] == 1): continue
        if (l[cx][cy] == 'F'):
            if (v[x][y][0] < v[cx][cy][0] or (v[x][y][0] == v[cx][cy][0] and v[x][y][1] < v[cx][cy][1])):
                heapq.heappush(hq, (v[x][y][0], v[x][y][1], cx, cy))
                v[cx][cy] = (v[x][y][0], v[x][y][1])
                continue
        onTrash = 1 if l[cx][cy] == 'g' else 0
        hasTrash = 0
        if (not onTrash):
            for j in range(4):
                ccx, ccy = cx + dx[j], cy + dy[j]
                if (ccx < 0 or ccx >= N or ccy < 0 or ccy >= M): continue
                if (l[ccx][ccy] == 'g'): hasTrash = 1
        v0, v1 =  v[x][y][0] + onTrash, v[x][y][1] + hasTrash
        if (v0 < v[cx][cy][0] or (v0 == v[cx][cy][0] and v1 < v[cx][cy][1])):
            heapq.heappush(hq, (v0, v1, cx, cy))
            v[cx][cy] = (v0, v1)

print(*(v[F[0]][F[1]]))
