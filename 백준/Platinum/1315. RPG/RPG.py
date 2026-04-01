import sys
sys.setrecursionlimit(10**5)

n = int(sys.stdin.readline())
l = []

dp = [[-1 for i in range(1010)] for j in range(1010)]
v = [0 for i in range(n + 1)]

for i in range(n):
    l.append(list(map(int, sys.stdin.readline().split())))

def DP(s, i):
    if (dp[s][i] != -1): return dp[s][i]
    dp[s][i] = 0

    vv = []
    pp = 0
    for j in range(n):
        if ((s >= l[j][0] or i >= l[j][1])):
            dp[s][i] += 1
            if (v[j]): continue
            v[j] = 1
            pp += l[j][2]
            vv.append(j)

    for j in range(pp + 1):
        dp[s][i] = max(dp[s][i], DP(min(1000, s + j), min(1000, i + (pp - j))))

    for j in vv:
        v[j] = 0

    return dp[s][i]

print(DP(1, 1))
