from sys import stdin

n = int(stdin.readline())
r = list(map(int, stdin.readline().split()))
c = list(map(int, stdin.readline().split()))
m = [[0 for i in range(n)] for i in range(n)]

if (sum(r) != sum(c)):
	print(-1)
else:
	for i in range(n):
		c[i] = [c[i], i]
	
	res = 0
	for i in range(n):
		c.sort(reverse=True)
		t = r[i]
		for j in range(r[i]):
			if (t == 0):
				break
			if (c[j][0] == 0):
				break
			c[j][0] -= 1
			m[i][c[j][1]] = 1
			t -= 1
		if (t):
			print(-1)
			res = 1
			break
	
	if (not res):
		print(1)
		for i in range(n):
			for j in range(n):
				m[i][j] = str(m[i][j])
			print(''.join(m[i]))
