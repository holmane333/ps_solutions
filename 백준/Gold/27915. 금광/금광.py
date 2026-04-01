from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10**8)

n = int(input())
ll = list(map(int, stdin.readline().split()))
l = [[] for i in range(n + 1)]
v = [0 for i in range(n + 1)]
for i in range(n - 1):
	l[ll[i]].append(i + 2)
x = 1
y = 0
def dfs(idx, t):
	#print(idx, t)
	global l, v, x, y
	for i in l[idx]:
		if (not v[i]):
			v[i] = 1
			dfs(i, t + 1)
			if ((t + 1) % 2 == 1):
				x += 1
			else:
				y += 1
v[1] = 1
dfs(1, 1)
print(max(x, y))
