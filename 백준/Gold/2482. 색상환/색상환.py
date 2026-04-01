import sys;input=lambda:sys.stdin.readline().rstrip()
MOD = 1_000_000_003

N = int(input())
K = int(input())

dp = [[0 for j in range(N + 5)] for i in range(N + 5)]

dp[0][0] = dp[1][0] = dp[1][1] = 1
for i in range(2, N + 1):
    dp[i][0] = 1
    dp[i][1] = i
    for j in range(2, K + 1):
        dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD
print((dp[N - 3][K - 1] + dp[N - 1][K]) % MOD)