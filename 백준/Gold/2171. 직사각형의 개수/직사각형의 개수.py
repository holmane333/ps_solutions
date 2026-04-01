from sys import stdin

n = int(stdin.readline())
l = []
for i in range(n):
	l.append(list(map(int, stdin.readline().split())))
l.sort()
l1 = []
for i in l:
	l1.append(i.copy())
ll = len(l)
l[0][0] = 0

#print(l, l1)
for i in range(1, ll):
	#print(l1[i][0], l1[i - 1][0])
	if (l1[i][0] == l1[i - 1][0]):
		l[i][0] = l[i - 1][0]
	else:
		l[i][0] = l[i - 1][0] + 1

#print(l, l1)
l.sort(key = lambda x:(x[1], x[0]))
l1 = []
for i in l:
	l1.append(i.copy())
l[0][1] = 0
for i in range(1, ll):
	if (l1[i][1] == l1[i - 1][1]):
		l[i][1] = l[i - 1][1]
	else:
		l[i][1] = l[i - 1][1] + 1

m = [[0 for i in range(5001)] for j in range(5001)]

cnt = 0
for i in range(ll):
	m[l[i][0]][l[i][1]] = 1

for i in range(ll):
	for j in range(i + 1, ll):
		p1 = l[i]
		p2 = l[j]
		if (p1[0] == p2[0] or p1[1] == p2[1]):
			continue
		if (m[p1[0]][p2[1]] and m[p2[0]][p1[1]]):
			cnt += 1

print(cnt // 2)