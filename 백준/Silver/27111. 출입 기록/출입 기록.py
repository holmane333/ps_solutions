from sys import stdin

n = int(stdin.readline())
l = [0 for i in range(200010)]

cnt = 0
for i in range(n):
	a, b = map(int, stdin.readline().split())
	if (b):
		if (l[a]):
			cnt += 1
		else:
			l[a] = 1
	else:
		if (l[a]):
			l[a] = 0
		else:
			cnt += 1

cnt += l.count(1)
print(cnt)