from sys import stdin

n = int(stdin.readline())
l = [[] for i in range(n + 1)]
res = ['-1' for i in range(n + 1)]
for i in range(n - 1):
	a, b = map(int, stdin.readline().split())
	l[a].append(b)
	l[b].append(a)

q = [1]
while q:
	a = q.pop(0)
	for i in l[a]:
		if (res[i] != '-1'):
			continue
		res[i] = str(a)
		q.append(i)

del res[0]
del res[0]
print('\n'.join(res))