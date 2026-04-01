from sys import stdin
 
n, k = map(int, stdin.readline().split())
 
x, y, t = 0, 0, 0
l = []
d = {}
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
dd = ['S', 'N', 'E', 'W']
cx, cy = 0, 0
for i in range(n):
	a, b = map(str, stdin.readline().split())
	b = int(b)
	for j in range(4):
		if (a == dd[j]):
			cx, cy = dx[j], dy[j]
			break
	for j in range(b):
		x += cx
		y += cy
		t += 1
		if ((x, y) in d):
			#print(x, y, d[(x, y)])
			l.append((x, y))
			d[(x, y)].append(t)
			#print(x, y, d[(x, y)])
		else:
			d[(x, y)] = [t]
l = list(set(l))
l2 = []
ll = len(l)
for i in range(ll):
	l2.append(d[l[i]])
left = 0
right = 1000001
ll = len(l2)
res = -1
while (left <= right):
	mid = (left + right) // 2
	cnt = 0
	for i in range(ll):
		prev = l2[i][0]
		for j in range(1, len(l2[i])):
			if (l2[i][j] - prev >= mid):
				cnt += 1
				prev = l2[i][j]
		#if (l[i] >= mid):
		#	cnt += 1
	if (cnt >= k):
		left = mid + 1
		res = max(res, mid)
	else:
		right = mid - 1
print(res)