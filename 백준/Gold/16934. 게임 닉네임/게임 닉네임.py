from sys import stdin

n = int(stdin.readline())
d = {}
res = []
for i in range(n):
	s = stdin.readline().rstrip()
	l = len(s)
	c = 0
	for j in range(1, l):
		st = s[0:j]
		if (st not in d):
			res.append(st)
			c = 1
			break
	if (not c):
		if (s not in d):
			res.append(s)
		else:
			if (d[s] == 0):
				res.append(s)
			else:
				res.append(s + str(d[s] + 1))
	for j in range(1, l):
		st = s[0:j]
		if (st not in d):
			d[st] = 0
	if (s not in d):
		d[s] = 1
	else:
		d[s] += 1

print('\n'.join(res))