import sys;input=lambda:sys.stdin.readline().rstrip()

N = 10
mat = [[*map(int, input().split())] for i in range(N)]

filled = [[0 for i in range(N)] for j in range(N)]
res = int(1e9)
used = [0 for i in range(6)]
cnt = 0
# print(mat)
# print(filled)
def dfs(x, y):
    # print(x, y)
    global N, res, cnt, mat, filled
    if (x > N - 1):
        res = min(res, cnt)
        return

    for i in range(1, 6):
        if (x + i > N or y + i > N): continue
        if (used[i] >= 5): continue
        check = 0
        for j in range(i):
            if (check): break
            for k in range(i):
                if (mat[x + j][y + k] and not filled[x + j][y + k]):
                    continue
                check = 1
                break
        if (not check):
            cnt += 1
            for j in range(i):
                for k in range(i):
                    filled[x + j][y + k] = 1
            used[i] += 1
            # print(x, y)
            # print(used)
            # print(filled)
            nx, ny = x + 1 if y + i >= N else x, (y + i) % N
            dfs(nx, ny)
            used[i] -= 1
            for j in range(i):
                for k in range(i):
                    filled[x + j][y + k] = 0
            cnt -= 1
    if ((mat[x][y] and filled[x][y]) or not mat[x][y]):
        nx, ny = x + 1 if y + 1 >= N else x, (y + 1) % N
        dfs(nx, ny)


dfs(0, 0)
print(res if res != int(1e9) else -1)
