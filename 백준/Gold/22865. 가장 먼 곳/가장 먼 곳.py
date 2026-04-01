from sys import stdin
from heapq import heappop, heappush

v = int(stdin.readline())
s = list(map(int, stdin.readline().split()))
e = int(stdin.readline())
edge = [[] for i in range(v + 10)]
distance1 = [1e9 for i in range(v + 1)]
distance2 = [1e9 for i in range(v + 1)]
distance3 = [1e9 for i in range(v + 1)]
for i in range(e):
	x, y, d = map(int, stdin.readline().split())
	edge[x].append((y, d))
	edge[y].append((x, d))
distance1[s[0]] = 0
distance2[s[1]] = 0;
distance3[s[2]] = 0;

h = [(0, s[0])]

while (h):
	cost, pos = heappop(h)
	for ppos, ccost in edge[pos]:
		if (distance1[ppos] > cost + ccost):
			distance1[ppos] = cost + ccost
			heappush(h, (cost + ccost, ppos))

h = [(0, s[1])]

while (h):
	cost, pos = heappop(h)
	for ppos, ccost in edge[pos]:
		if (distance2[ppos] > cost + ccost):
			distance2[ppos] = cost + ccost
			heappush(h, (cost + ccost, ppos))

h = [(0, s[2])]

while (h):
	cost, pos = heappop(h)
	for ppos, ccost in edge[pos]:
		if (distance3[ppos] > cost + ccost):
			distance3[ppos] = cost + ccost
			heappush(h, (cost + ccost, ppos))

res = 1
val = min(distance1[1], distance2[1], distance3[1])
for i in range(1, len(distance1)):
	if (val < min(distance1[i], distance2[i], distance3[i])):
		val = min(distance1[i], distance2[i], distance3[i])
		res = i

print(res)
