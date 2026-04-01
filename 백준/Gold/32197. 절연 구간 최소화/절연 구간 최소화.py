from sys import stdin
import heapq

n, m = map(int, stdin.readline().split())
l = [[] for i in range(n + 2)]
for i in range(m):
    a, b, c = map(int, stdin.readline().split())
    l[a].append((b, c))
    l[b].append((a, c))
a, b = map(int, stdin.readline().split())

q = []
v = [10000007 for i in range(n + 2)]
v[a] = 0
for i in l[a]:
    v[i[0]] = 0
    q.append((0, i[0], i[1]))
heapq.heapify(q)
while (q):
    t = heapq.heappop(q)
    for i in l[t[1]]:
        if (v[i[0]] <= v[t[1]] + (t[2] ^ i[1])): continue
        v[i[0]] = v[t[1]] + (t[2] ^ i[1])
        heapq.heappush(q, (v[t[1]] + (t[2] ^ i[1]), i[0], i[1]))

print(v[b])