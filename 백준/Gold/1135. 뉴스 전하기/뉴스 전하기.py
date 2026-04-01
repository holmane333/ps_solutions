from sys import stdin

global n, v
n = int(stdin.readline())
l = list(map(int, stdin.readline().split()))
v = [[] for i in range(n + 1)]

for i in range(1, n):
	v[l[i]].append(i)

def dfs(idx):
	global n, v
	m = 0
	l1 = []
	for i in v[idx]:
		l1.append(dfs(i))
	
	l1.sort(reverse=True)
	l1l = len(l1)
	for i in range(l1l):
		l1[i] += i + 1
		m = max(m, l1[i])
	
	return m

print(dfs(0))