from sys import stdin
import heapq
n = int(stdin.readline())
h = list(map(int, stdin.readline().split()))
for i in range(n - 1):
	for j in list(map(int, stdin.readline().split())):
		heapq.heappush(h, j)
		heapq.heappop(h)
print(heapq.heappop(h))