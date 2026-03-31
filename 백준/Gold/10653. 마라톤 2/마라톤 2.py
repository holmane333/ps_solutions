import sys;input=lambda:sys.stdin.readline().rstrip()

N, K = map(int, input().split())
l = [[*map(int, input().split())] for _ in range(N)]
distances = [[0] * N for i in range(N)]

def getDisstance(x, y):
    return abs(l[x][0] - l[y][0]) + abs(l[x][1] - l[y][1])

for i in range(N):
    for j in range(i, N):
        distances[i][j] = distances[j][i] = getDisstance(i, j)

dp = [[-1] * (N + 1) for _ in range(N + 1)]

def DP(idx, cnt):
    if (idx >= N - 1): return 0
    if (dp[idx][cnt] != -1): return dp[idx][cnt]
    dp[idx][cnt] = int(1e9)
    for i in range(idx + 1, min(idx + K - cnt + 2, N)):
        dp[idx][cnt] = min(dp[idx][cnt], DP(i, cnt + (i - idx - 1)) + distances[idx][i])
    return dp[idx][cnt]

print(DP(0, 0))