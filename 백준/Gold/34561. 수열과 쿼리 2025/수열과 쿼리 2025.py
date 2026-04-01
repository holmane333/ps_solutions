import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
l = [0] + list(map(int, input().split()))
M = int(input())
parent = [i for i in range(500010)]
d = dict()

def getParent(a: int) -> int:
    root = a
    while parent[root] != root: root = parent[root]
    next_a = parent[a]
    while a != root: next_a, parent[a], a = parent[a], root, next_a
    return root

def unionFind(a:int, b: int) -> None:
	a = getParent(a)
	b = getParent(b)
	parent[b] = a

ll = [0 for i in range(N + 1)]
g = 1
gro = [0 for i in range(500010)]
for i in range(1, N + 1):
	if (l[i] not in d):
		d[l[i]] = g
		gro[g] = l[i]
		g += 1
	ll[i] = d[l[i]]

res = []
for i in range(M):
	q = list(map(int, input().split()))
	if (q[0] == 1):
		if (q[1] not in d or q[1] == q[2]): continue
		if (q[2] in d):
			unionFind(d[q[2]], d[q[1]])
			del d[q[1]]
		else:
			d[q[2]] = getParent(d[q[1]])
			gro[d[q[2]]] = q[2]
			del d[q[1]]
	else:
		res.append(str(gro[getParent(ll[q[1]])]))
print('\n'.join(res))
