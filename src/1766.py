from sys import stdin
import heapq

n, m = map(int, stdin.readline().rstrip().split())
l = [1 for _ in range(n + 1)]
pair = [[] for _ in range(n + 1)]
pair2 = [[] for _ in range(n + 1)]
min_heap = []

for i in range(m):
	a, b = map(int, stdin.readline().rstrip().split())
	pair[a].append(b)
	pair2[b].append(a)
	l[b] = 0

for i in range(1, n + 1):
	if (l[i] == 1):
		heapq.heappush(min_heap, i)

res = []
while (min_heap):
	t = heapq.heappop(min_heap)
	res.append(str(t))
	for i in pair[t]:
		pair2[i].remove(t)
		if (pair2[i] == []):
			heapq.heappush(min_heap, i)

print(' '.join(res))