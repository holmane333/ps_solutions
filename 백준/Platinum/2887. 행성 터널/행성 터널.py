from sys import stdin
import math

parent = [i for i in range(100002)]
e = []

def getParent(a):
	if (a == parent[a]):
		return a
	parent[a] = getParent(parent[a])
	return parent[a]

def distance(a1, b1, c1, a2, b2, c2):
	dis = min(abs(a1 - a2), abs(b1 - b2), abs(c1 - c2))
	return dis

def unionFind(a, b):
	a = getParent(a)
	b = getParent(b)
	
	if (a != b):
		if (a < b):
			parent[b] = a
		else:
			parent[a] = b


n = int(stdin.readline().rstrip())
lx = []
ly = []
lz = []

for i in range(n):
	a, b, c = map(int, stdin.readline().rstrip().split())
	lx.append([a, i])
	ly.append([b, i])
	lz.append([c, i])

lx.sort(key = lambda x:x[0])
ly.sort(key = lambda x:x[0])
lz.sort(key = lambda x:x[0])

for i in range(0, n - 1):
	e.append([lx[i + 1][0] - lx[i][0], [lx[i + 1][1], lx[i][1]]])
	e.append([ly[i + 1][0] - ly[i][0], [ly[i + 1][1], ly[i][1]]])
	e.append([lz[i + 1][0] - lz[i][0], [lz[i + 1][1], lz[i][1]]])

e.sort(key = lambda x:x[0])

res = 0
for i in e:
	if (getParent(i[1][0]) != getParent(i[1][1])):
		res += i[0]
		unionFind(i[1][0], i[1][1])
	
print(res)