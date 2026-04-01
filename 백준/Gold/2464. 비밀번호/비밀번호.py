from sys import stdin

n = int(stdin.readline())
s = []
while (n):
	s.append(n % 2)
	n //= 2
s.append(0)
s.append(0)
l = len(s)
r1 = s.copy()
r2 = s.copy()
c = 0
p = -1
res = []
cnt = 0
for i in range(l):
	if (r1[i] == 1):
		cnt += 1
		if (p != -1):
			r1[i] = 0
			r1[p] = 1
			c = 1
			break
	else:
		if (r1[i] == 0):
			p = i

if (not c):
	res.append(0)
else:
	cnt -= 1
	for i in range(p):
		r1[i] = 0
	for i in range(p - cnt, p):
		r1[i] = 1
	t = 0
	for i in range(l):
		t += (r1[i] << i)
	res.append(t)

p = -1
cnt = 0
for i in range(l):
	if (r2[i] == 0 and p != -1):
		r2[i] = 1
		r2[p] = 0
		c = 1
		break
	else:
		if (r2[i] == 1):
			p = i
			cnt += 1

t = 0
cnt -= 1
for i in range(p):
	r2[i] = 0
for i in range(cnt):
	r2[i] = 1
for i in range(l):
	t += (r2[i] << i)
res.append(t)

print("%d %d"%(res[0], res[1]))