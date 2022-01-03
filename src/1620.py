from sys import stdin

n, m = map(int, stdin.readline().rstrip().split())
l = []
d = {}
for i in range(n):
	l.append(stdin.readline().rstrip())
	d[l[i]] = i + 1
for i in range(m):
	a = stdin.readline().rstrip()
	if (a.isdigit()):
		a = int(a)
		print(l[a - 1])
	else:
		print(d[a])
