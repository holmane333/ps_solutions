from sys import stdin

n, m = map(int, stdin.readline().split())
d = {stdin.readline().rstrip() : i for i in range(n)}
c = 0

for i in range(m):
	if (stdin.readline().rstrip() in d):
		c += 1
print(c)