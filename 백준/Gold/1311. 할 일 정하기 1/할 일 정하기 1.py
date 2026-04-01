import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
l = [[0]] + [list(map(int, input().split())) for i in range(N)]
l = [[0] + i for i in l]

dp = [[1e9 for j in range((1 << N) + 5)] for i in range(22)]

dp[0][0] = 0
for i in range(1, N + 1):
    for j in range((1 << N)):
        if (dp[i - 1][j] == 1e9): continue
        b = 1
        t = 1
        while (b < (1 << N)):
            if (not (j & b)):
                dp[i][j | b] = min(dp[i][j | b], l[i][t] + dp[i - 1][j])
            b <<= 1
            t += 1

print(dp[N][(1 << N) - 1])