import sys;input=lambda:sys.stdin.readline().rstrip()
INF = float('inf')

N = int(input())
e = [[] for _ in range(N + 1)]
child, parent = [[] for _ in range(N + 1)], [0 for _ in range(N + 1)]

for _ in range(N - 1):
    U, V = map(int, input().split())
    e[U].append(V)
    e[V].append(U)

q = [1]
stack = [1]
parent[1] = -1
while q:
    node = q.pop()
    for i in e[node]:
        if parent[i] == 0:
            parent[i] = node
            child[node].append(i)
            q.append(i)
            stack.append(i)

dp = [[0, 0] for _ in range(N + 1)]

while stack:
    node = stack.pop()
    dp[node][0], dp[node][1] = 0, 1
    for i in child[node]:
        dp[node][1] += min(dp[i][0], dp[i][1])
        dp[node][0] += dp[i][1]

print(min(dp[1][0], dp[1][1]))