from sys import stdin

global l1, l2, k, g
n, g, k = map(int, stdin.readline().split())
l1 = []
l2 = []
for i in range(n):
	l = list(map(int, stdin.readline().split()))
	if (l[2] == 1):
		l1.append(l)
	else:
		l2.append(l)


def check(m):
	global l1, l2, k, g
	l = []
	r = 0
	for i in l1:
		l.append(i[0] * max(1, m - i[1]))
	for i in l2:
		r += i[0] * max(1, m - i[1])
	l.sort()
	ll = len(l)
	for i in range(ll - k):
		r += l[i]
	if (g >= r):
		return 1
	else:
		return 0
	
res = 0
s = 1
e = 10000000001

while (s <= e):
	m = (s + e) // 2
	if (check(m)):
		res = max(res, m)
		s = m + 1
	else:
		e = m - 1
	
print(res)