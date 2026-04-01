from sys import stdin
import heapq

n = int(stdin.readline().rstrip())
l = []
for i in range(n):
	a, b = map(int, stdin.readline().rstrip().split())
	l.append([a, b])
l.sort()
min_heap = []
cnt = 1
for i in range(n):
	while(len(min_heap) != 0 and min_heap[0] <= l[i][0]):
		heapq.heappop(min_heap)
	heapq.heappush(min_heap, l[i][1])
	if (cnt < len(min_heap)):
		cnt = len(min_heap)
print(cnt)