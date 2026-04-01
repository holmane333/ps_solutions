from sys import stdin

tcc = int(stdin.readline())
prime = []
v = [0 for i in range(100010)]
for i in range(2, 100001):
	if (not v[i]):
		v[i] = 1;
		prime.append(i)
		for j in range(i * i, 100001, 2 * i):
			v[j] = 1;

for tc in range(1, tcc + 1):
	a, b, n = map(int, stdin.readline().split())
	d = {}
	p = []
	res = b - a + 1
	while (n != 1):
		c = 0
		for i in prime:
			if (not (n % i)):
				n //= i
				d[i] = 1
				c = 1
				break
		if (not c):
			break
	if (n != 1):
		d[n] = 1
	for i in d.keys():
		p.append(i)
	
	lenofp = len(p)
	size = (1 << lenofp)
	for i in range(1, size):
		cnt = 0
		pro = 1;
		for j in range(size):
			if (i & (1 << j)):
				cnt += 1
				pro *= p[j]
		l = b // pro - (a + pro - 1) // pro + 1;
		
		#print(l, cnt, pro, res)
		if (1 > l):
			continue
		if (cnt % 2):
			res -= l
		else:
			res += l
	
	print("Case #%d: %d"%(tc, res))