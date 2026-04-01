from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10**8)

global l, n, v, count

n, m, r = map(int, stdin.readline().split())
l = [[] for i in range(n + 1)]
v = [0 for i in range(n + 1)]
v[r] = 1;
count = 1;
for i in range(m):
	a, b = map(int, stdin.readline().split())
	l[a].append(b)
	l[b].append(a)

for i in range(n + 1):
	l[i].sort()

def bfs(a):
	global l, n, v, count
	q = [a]
	while (q):
		a = q.pop(0)
		for i in range(len(l[a])):
			if (not v[l[a][i]]):
				count += 1
				v[l[a][i]] = count
				q.append(l[a][i])

bfs(r)
for i in range(1, n + 1):
	print(v[i])