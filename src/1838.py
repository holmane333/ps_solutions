from sys import stdin

n = int(stdin.readline().rstrip())
l = []
t = list(map(int, stdin.readline().rstrip().split()))
for i in range(n):
	l.append([t[i], i])

l.sort()
res = 0
for i in range(n):
	res = max(res, l[i][1] - i)

print(res)