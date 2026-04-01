import sys;input=lambda:sys.stdin.readline().rstrip()
MOD = 1_000_000_007

N, E = map(int, input().split())
dp = [[0 for i in range(510)] for j in range(510)]
dp[1][0] = 1
sdp = [[0 for i in range(510)] for j in range(510)]
for i in range(2, 501):
    for j in range(500, -1, -1):
        sdp[i - 1][j] = (sdp[i - 1][j + 1] + dp[i - 1][j]) % MOD
    for j in range(501):
        for k in range(1, i - 1):
            dp[i][j] += (sdp[k][j] * sdp[i - k - 1][j] - sdp[k][j + 1] * sdp[i - k - 1][j + 1]) % MOD
            dp[i][j] %= MOD
        if (j): dp[i][j] += dp[i - 1][j - 1]
        dp[i][j] %= MOD

print(dp[N][E])