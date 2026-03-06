import sys;input=lambda:sys.stdin.readline().rstrip()

def dfs(N, index, cnt, depth):
    global res
    if (depth == N):
        res = min(res, cnt + l[index][0])
        return
    for i in range(N):
        if (not visit[i] and cnt + l[index][i] < res):
            visit[i] = 1
            dfs(N, i, cnt + l[index][i], depth + 1)
            visit[i] = 0

N = int(input())
l = [[*map(lambda x: int(1e9) if x == '0' else int(x), input().split())] for i in range(N)]

res = int(1e9)
visit = [0 for i in range(N)]
visit[0] = 1

dfs(N, 0, 0, 1)
print(res)