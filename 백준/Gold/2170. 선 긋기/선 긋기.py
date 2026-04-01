from sys import stdin

n = int(stdin.readline())
l = []
for i in range(n):
	l.append(list(map(int, stdin.readline().rstrip().split())))
l.sort()

res = 0
start = l[0][0]
end = l[0][1]
for i in range(1, n):
	if (end >= l[i][0]):
		if (end < l[i][1]):
			end = l[i][1]
	else:
		res += end - start
		start = l[i][0]
		end = l[i][1]

res += end - start

print(res)