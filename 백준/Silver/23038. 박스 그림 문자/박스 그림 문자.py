from sys import stdin

n, m = map(int, stdin.readline().split())
ary = []
for i in range(n * 3):
	ary.append(list(stdin.readline().rstrip()))

for i in range(n):
	for j in range(m):
		if (ary[i * 3 + 1][j * 3 + 1] == '#'):
			continue
		ary[i * 3 + 1][j * 3 + 1] = '#'
		if (i != 0 and ary[i * 3 - 1][j * 3 + 1] == '#'):
			ary[i * 3][j * 3 + 1] = '#'
		if (j != 0 and ary[i * 3 + 1][j * 3 - 1] == '#'):
			ary[i * 3 + 1][j * 3] = '#'
		if (i != n - 1 and ary[i * 3 + 3][j * 3 + 1] == '#'):
			ary[i * 3 + 2][j * 3 + 1] = '#'
		if (j != m - 1 and ary[i * 3 + 1][j * 3 + 3] == '#'):
			ary[i * 3 + 1][j * 3 + 2] = '#'

for i in range(n * 3):
	ary[i] = ''.join(ary[i])
print("\n".join(ary))