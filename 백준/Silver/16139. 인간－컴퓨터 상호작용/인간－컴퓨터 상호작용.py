from sys import stdin
from string import ascii_lowercase

s = stdin.readline().rstrip()
s = '1' + s
n = int(stdin.readline().rstrip())
res = []
ls = len(s)
l = list(ascii_lowercase)
l.insert(0, '0')
cnt = [[0 for j in range(ls + 2)] for i in range(28)]

for i in range(27):
	for j in range(ls):
		if (j): cnt[i][j] = cnt[i][j - 1]
		if (s[j] == l[i]):
			cnt[i][j] += 1

for i in range(n):
	a, b, c = map(str, stdin.readline().split())
	b, c = int(b), int(c)
	#print(ord(a) - 96, c + 1, b)
	res.append(str(cnt[ord(a) - 96][c + 1] - cnt[ord(a) - 96][b]))
print('\n'.join(res))