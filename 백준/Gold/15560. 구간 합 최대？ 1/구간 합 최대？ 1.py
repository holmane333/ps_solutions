import sys;input=lambda:sys.stdin.readline().rstrip()

N, Q, U, V = map(int, input().split())
l = list(map(int, input().split()))
l = [0] + [i * U + V for i in l]

for _ in range(Q):
    c, a, b = map(int, input().split())
    if (c): l[a] = b * U + V
    else:
        dp = [-float('inf') for i in range(N + 1)]
        res = dp[0]
        for i in range(a, b + 1):
            dp[i] = max(dp[i - 1] + l[i], l[i])
            res = max(res, dp[i])
        print(res - V)