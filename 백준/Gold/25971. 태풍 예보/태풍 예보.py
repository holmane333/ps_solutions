from sys import stdin

def distance(x1, y1, x2, y2):
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)


n, k, r, q = map(int, stdin.readline().split())
r *= r
t = [[*map(int, stdin.readline().split())] for _ in range(k)]
l = [[] for _ in range(200010)]
res = ["gori" for _ in range(q)]

for i in range(q):
	a, b, c = map(int, stdin.readline().split())
	l[a].append([b, c, i])

lt = len(t)
pred, prex, prey = t[0][0], t[0][1], t[0][2]
for i in range(1, lt):
	d, x, y = t[i][0], t[i][1], t[i][2]
	if (x != prex):
		if (x < prex): h = 1 #북쪽
		else: h = 2 #남쪽
	else:
		if (y < prey): h = 3 #서쪽
		else: h = 4 #동쪽
	if (d == n): d += 1
	for j in range(pred, d):
		for m in l[j]:
			dis = distance(prex, prey, m[0], m[1])
			#print(j, dis, r, h, prex, prey, m[0], m[1], m[2])
			if (dis <= r):
				c = "gori"
				if (h == 1):
					if (prey < m[1]):
						c = "unsafe"
					elif (prey > m[1]):
						c = "safe"
				elif (h == 2):
					if (prey > m[1]):
						c = "unsafe"
					elif (prey < m[1]):
						c = "safe"
				elif (h == 3):
					if (prex > m[0]):
						c = "unsafe"
					elif (prex < m[0]):
						c = "safe"
				else:
					if (prex < m[0]):
						c = "unsafe"
					elif (prex > m[0]):
						c = "safe"
				res[m[2]] = c
		if (h == 1): prex -= 1
		elif (h == 2): prex += 1
		elif (h == 3): prey -= 1
		else: prey += 1
		pred += 1

print('\n'.join(res))