import sys;input=lambda:sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**9)

N = int(input())
l = [0] + list(map(int, input().split()))
e = [[] for i in range(N + 1)]
child, parent = [[] for i in range(N + 1)], [0 for i in range(N + 1)]

for i in range(N - 1):
    U, V = map(int, input().split())
    e[U].append(V)
    e[V].append(U)

def makeTree(node: int, p: int) -> None:
    for i in e[node]:
        if (p == i): continue
        parent[i] = node
        child[node].append(i)
        makeTree(i, node)

makeTree(1, -1)

dp = [[-1, -1] for i in range(N + 1)]

def DP(x: int, check: int) -> int:
    if (x > N): return 0
    if (dp[x][check] != -1): return dp[x][check]
    dp[x][check] = 0
    if (check):
        dp[x][check] = l[x]
        for i in child[x]: dp[x][check] += DP(i, 0)
    else:
        for i in child[x]: dp[x][check] += max(DP(i, 0), DP(i, 1))
    return dp[x][check]
    
print(max(DP(1, 0), DP(1, 1)))