from sys import stdin
mod = 1000000007

dp = [[0 for i in range(2)] for j in range(1000010)]
 
dp[1][0] = 3
dp[1][1] = 4
for i in range(2, 1000001):
    dp[i][0] = (dp[i - 1][0] * 3 + dp[i - 1][1]) % mod
    dp[i][1] = (dp[i - 1][0] * 4 + dp[i - 1][1] * 2) % mod
    

for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    print((dp[n][0] + dp[n][1]) % mod)