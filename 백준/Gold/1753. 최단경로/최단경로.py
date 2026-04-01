from sys import stdin
from heapq import heappop, heappush

v, e = map(int, stdin.readline().split())
s = int(stdin.readline())
edge = [[] for i in range(v + 10)]
distance = [1e9 for i in range(v + 1)]
for i in range(e):
	x, y, d = map(int, stdin.readline().split())
	edge[x].append((y, d))
distance[s] = 0

h = [(0, s)]

while (h):
	cost, pos = heappop(h)
	for ppos, ccost in edge[pos]:
		if (distance[ppos] > cost + ccost):
			distance[ppos] = cost + ccost
			heappush(h, (cost + ccost, ppos))

del distance[0]
for i in range(len(distance)):
	if (distance[i] == 1e9):
		distance[i] = "INF"
print(*distance, sep='\n')
