# slope trick
from sys import stdin
import heapq

n = int(stdin.readline())
q = []
l = list(map(int, stdin.readline().split()))
res = []
for idx, i in enumerate(l):
    i -= idx
    heapq.heappush(q, -i)
    res.append(-q[0])
    heapq.heappush(q, -i)
    heapq.heappop(q)
for i in range(len(res) - 1, 0, -1): res[i - 1] = min(res[i], res[i - 1])
for i in range(len(res)): res[i] += i
print('\n'.join(map(str, res)))