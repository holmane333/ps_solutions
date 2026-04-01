from sys import stdin

n = int(stdin.readline())
l = [0] + list(map(int, stdin.readline().split()))
dp = [[-1 for i in range(500010)] for j in range(51)]
dp[0][0] = 0
for i in range(1, n + 1):
    for j in range(500001 - l[i]):
        if (dp[i - 1][j] == -1): continue
        idx = j - l[i]
        diff = 0
        if (idx < 0):
            idx *= -1
            diff = idx
        dp[i][idx] = max(dp[i][idx], dp[i - 1][j] + diff)
        dp[i][j] = max(dp[i][j], dp[i - 1][j])
        dp[i][j + l[i]] = max(dp[i][j + l[i]], dp[i - 1][j] + l[i])

if (dp[n][0]): print(dp[n][0])
else: print(-1)