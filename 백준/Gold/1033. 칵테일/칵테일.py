from sys import stdin
n = int(stdin.readline())
global l, v, r
l = [[] for i in range(n + 1)]
v = []
r = [1 for i in range(n)]

def gcd(c, d):
	while (d > 0):
		t = c
		c = d
		d = t % c
	return c

def dfs(a, c):
	v[a] = 1
	r[a] *= c
	for i in l[a]:
		if (not v[i]):
			dfs(i, c)

for i in range(n - 1):
	a, b, c, d = map(int, stdin.readline().split())
	g = gcd(c, d)
	v = [0 for i in range(n + 1)]
	t1 = r[a]
	t2 = r[b]
	dfs(a, c // g * t2)
	dfs(b, d // g * t1)
	l[a].append(b)
	l[b].append(a)

g = r[0]
for i in range(1, n):
	g = gcd(g, r[i])

for i in range(n):
	r[i] //= g
print(*r)