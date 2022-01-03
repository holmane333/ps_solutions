from sys import stdin
import math

parent = [i for i in range(1002)]
e = []

def getParent(a):
	if (a == parent[a]):
		return a
	parent[a] = getParent(parent[a])
	return parent[a]

def distance(a1, b1, a2, b2):
	x = (a1 - a2) * (a1 - a2)
	y = (b1 - b2) * (b1 - b2)
	dis = math.sqrt(x + y)
	
	return dis

def unionFind(a, b):
	a = getParent(a)
	b = getParent(b)
	
	if (a != b):
		if (a < b):
			parent[b] = a
		else:
			parent[a] = b


n, m = map(int, stdin.readline().rstrip().split())
l = [[0, 0]]
for i in range(n):
	a, b = map(float, stdin.readline().rstrip().split())
	l.append([a, b])

for i in range(m):
	a, b = map(int, stdin.readline().rstrip().split())
	unionFind(a, b)

for i in range(1, n + 1):
	for j in range(i + 1, n + 1):
		e.append([distance(l[i][0], l[i][1], l[j][0], l[j][1]), [i, j]])

e.sort(key = lambda x:x[0])

res = 0.0
for i in e:
	if (getParent(i[1][0]) != getParent(i[1][1])):
		res += i[0]
		unionFind(i[1][0], i[1][1])
	
print("%.2f"%res)