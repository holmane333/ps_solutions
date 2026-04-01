from sys import stdin

n = int(stdin.readline())
l = []
res = 1
for i in range(n):
	l.append([*map(int, stdin.readline().split())])
l.sort()
for i in range(n - 1):
	if (l[i + 1][0] - l[i][0] > l[i][1]):
		res += 1
print(res)
