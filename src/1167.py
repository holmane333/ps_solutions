import sys
sys.setrecursionlimit(10**6)

Max = 0
idx = 1

def dfs(l, v, x, cnt):
	global Max, idx
	if (Max < cnt):
		Max = cnt
		idx = x
	for i in l[x]:
		if (v[i[0]] == 1):
			continue
		v[i[0]] = 1
		t = dfs(l, v, i[0], cnt + i[1])

n = int(sys.stdin.readline())
l = [[] for i in range(n + 1)]
v = [0 for i in range(n + 1)]
v2 = v.copy()
for i in range(n):
	a = list(map(int, sys.stdin.readline().split()))
	a.pop()
	for i in range(1, len(a), 2):
		l[a[0]].append([a[i], a[i + 1]])
		l[a[i]].append([a[0], a[i + 1]])

v[1] = 1
dfs(l, v, 1, 0)
Max = 0
v2[idx] = 1
dfs(l, v2, idx, 0)
print(Max)