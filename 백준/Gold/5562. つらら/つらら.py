from sys import stdin
import sys
sys.setrecursionlimit(1000000)

n, l = map(int, stdin.readline().split())

arr = []
for i in range(n):
    arr.append(int(stdin.readline()))

dp = [-1] * (n + 1)

def DP(idx):
    if (dp[idx] != -1): return dp[idx]
    dp[idx] = 0
    
    if (idx > 0 and arr[idx] < arr[idx - 1]):
        dp[idx] = max(dp[idx], DP(idx - 1))
    
    if (idx < n - 1 and arr[idx] < arr[idx + 1]):
        dp[idx] = max(dp[idx], DP(idx + 1))
    
    dp[idx] += max(0, l - arr[idx])
    
    return dp[idx]

res = 0
for i in range(n):
    res = max(res, DP(i))

print(res)