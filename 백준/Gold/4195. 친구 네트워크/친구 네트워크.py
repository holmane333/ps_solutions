from sys import stdin

def getParent(a, l):
	if (a == l[a]): return a
	l[a] = getParent(l[a], l)
	return l[a]

def unionFind(a, b, l, v):
	a = getParent(a, l)
	b = getParent(b, l)
	
	if (a > b):
		l[a] = b
		v[b] += v[a]
	elif (a < b):
		l[b] = a
		v[a] += v[b]

tc = int(stdin.readline())
while (tc):
	n = int(stdin.readline())
	idx = 1
	l = [i for i in range(200020)]
	v = [0 for i in range(200020)]
	d = dict()
	for i in range(n):
		a, b = map(str, stdin.readline().split())
		a1, b1 = 0, 0
		if (not a in d):
			d[a] = idx
			v[idx] += 1
			idx += 1
		if (not b in d):
			d[b] = idx
			v[idx] += 1
			idx += 1
		a1 = d[a]
		b1 = d[b]
		if (getParent(a1, l) != getParent(b1, l)):
			unionFind(a1, b1, l, v)
		print(v[l[getParent(a1, l)]])
	tc -= 1
	