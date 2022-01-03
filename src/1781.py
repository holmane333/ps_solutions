from sys import stdin
import heapq

n = int(stdin.readline())

l = []
for _ in range(n):
	a, b = map(int, stdin.readline().split())
	l.append([a, b])
l.sort(key = lambda x : (-x[0], -x[1]))
#print(l)

maxh = []
i, t = 0, n
res = 0
while (t > 0):
	while(i < n and l[i][0] == t):
		heapq.heappush(maxh, -l[i][1])
		i += 1
	if (maxh != []):
		res += -(heapq.heappop(maxh))
	t -= 1

print(res)
	