from sys import stdin

n = int(stdin.readline().rstrip())
l = []
for i in range(n):
	l.append([int(stdin.readline().rstrip()), i])

l.sort()
res = 0
for i in range(n):
	res = max(res, l[i][1] - i)

print(res + 1)