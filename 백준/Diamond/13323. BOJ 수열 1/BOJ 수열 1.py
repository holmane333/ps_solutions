# slope trick
from sys import stdin
import heapq

n = int(stdin.readline())
q = []
l = list(map(int, stdin.readline().split()))
res = 0
for idx, i in enumerate(l):
    i -= idx
    heapq.heappush(q, -i)
    res += (-q[0]) - i
    heapq.heappush(q, -i)
    heapq.heappop(q)
print(res)