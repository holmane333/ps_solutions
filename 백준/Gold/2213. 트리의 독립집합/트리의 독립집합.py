import sys;input=lambda:sys.stdin.readline().rstrip()
INF = float('inf')

N = int(input())
l = [0] + list(map(int, input().split()))
e = [[] for _ in range(N + 1)]
child, parent = [[] for _ in range(N + 1)], [0 for _ in range(N + 1)]

for _ in range(N - 1):
    U, V = map(int, input().split())
    e[U].append(V)
    e[V].append(U)

q = [1]
stack = [1]
parent[1] = -1
while (q):
    node = q.pop()
    for i in e[node]:
        if parent[i] == 0:
            parent[i] = node
            child[node].append(i)
            q.append(i)
            stack.append(i)

re = stack.copy()
dp = [[0, 0] for _ in range(N + 1)]

while (stack):
    node = stack.pop()
    dp[node][0], dp[node][1] = 0, l[node]
    for i in child[node]:
        dp[node][1] += dp[i][0]
        dp[node][0] += max(dp[i][0], dp[i][1])

q.append((1, 0))
res = []
while (q):
    node, pre = q.pop()
    c = 0
    if (not pre):
        c = 1 if dp[node][1] > dp[node][0] else 0
        if (c): res.append(node)
    for i in child[node]:
        q.append((i, c))

print(max(dp[1][0], dp[1][1]))
print(*sorted(res))