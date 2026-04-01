import sys;input=lambda:sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**9)

N, R, Q = map(int, input().split())
e = [[] for i in range(N + 1)]
s = [0 for i in range(N + 1)]
child, parent = [[] for i in range(N + 1)], [0 for i in range(N + 1)]

for i in range(N - 1):
    U, V = map(int, input().split())
    e[U].append(V)
    e[V].append(U)

def makeTree(node: int, p: int) -> None:
    s[node] = 1
    for i in e[node]:
        if (p == i): continue
        parent[i] = node
        child[node].append(i)
        makeTree(i, node)
        s[node] += s[i]

makeTree(R, -1)
res = []
for i in range(Q):
    res.append(str(s[int(input())]))
print('\n'.join(res))