from sys import stdin
import heapq

n, m = map(int, stdin.readline().split())
h = list(map(int, stdin.readline().split()))

heapq.heapify(h)

for i in range(m):
	a = heapq.heappop(h)
	b = heapq.heappop(h)
	heapq.heappush(h, a + b)
	heapq.heappush(h, a + b)

print(sum(h))