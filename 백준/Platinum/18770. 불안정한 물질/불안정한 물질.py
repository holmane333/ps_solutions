from sys import stdin
import sys
sys.setrecursionlimit(500000)


def solve_adj(x, rev):
    if (v[x] != (-1, -1)): return v[x]
    tmp1, tmp2 = w[x], 0
    for i in adj[x]:
        if (i == rev): continue
        data1, data2 = solve_adj(i, x)
        tmp1 += data2
        tmp2 += data1
    v[x] = (max(tmp1, tmp2), tmp2)
    return v[x]

def solve_cycle(cycle):
    n = len(cycle)
    if n == 0:
        return 0
    if n == 1:
        return w[cycle[0]]
    dp = [list(solve_adj(cycle[i], cycle[i - 1])) for i in range(len(cycle))]
    dp1 = [dp[i].copy() for i in range(len(dp))]
    dp2 = [dp[i].copy() for i in range(len(dp))]
    dp1[-1][0] -= w[cycle[-1]]
    dp2[0][0] -= w[cycle[0]]
    for i in range(1, n):
        dp1[i][0] += dp1[i - 1][1]
        dp1[i][1] += max(dp1[i - 1][0], dp1[i - 1][1])
    for i in range(1, n):
        dp2[i][0] += dp2[i - 1][1]
        dp2[i][1] += max(dp2[i - 1][0], dp2[i - 1][1])
    return max(max(dp1[-1]), max(dp2[-1]))

res = []
for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    w = [0 for i in range(n + 1)]
    Q = w.copy()
    visit = w.copy()
    v = [(-1, -1) for i in range(n + 1)]
    for i in range(1,n+1):
        a, b = map(int, stdin.readline().split())
        w[i] = a
        Q[i] = b

    adj = [[] for _ in range(n + 1)]
    for i in range(1,n + 1):
        adj[Q[i]].append(i)
    
    ans = 0
    for i in range(1, n + 1):
        if visit[i]:
            continue
        stack = []
        u = i
        while not visit[u]:
            visit[u] = 1
            stack.append(u)
            u = Q[u]
        if visit[u] == 1:
            cycle = []
            while stack:
                x = stack.pop()
                cycle.append(x)
                if x == u:
                    break
            cycle.reverse()
            ans += solve_cycle(cycle)
        for x in stack:
            visit[x] = 2
        cur = u
        while visit[cur] == 1:
            visit[cur] = 2
            cur = Q[cur]
    res.append(str(ans))
print('\n'.join(res))