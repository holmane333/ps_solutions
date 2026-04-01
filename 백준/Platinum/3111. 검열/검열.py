from sys import stdin
from collections import deque

a = stdin.readline().rstrip()
t = stdin.readline().rstrip()

lq = deque()
rq = deque()

lidx = 0
ridx = len(t) - 1
k = len(a)

while (lidx <= ridx):
	while (lidx <= ridx):
		c = 0
		lq.append(t[lidx])
		lidx += 1
		if (len(lq) >= k and lq[-1] == a[-1]):
			c = 1
			for i in range(k):
				if (lq[len(lq) - k + i] != a[i]):
					c = 0
					break
		if (c == 1):
			for i in range(k):
				lq.pop()
			break
		
	while (lidx <= ridx):
		c = 0
		rq.appendleft(t[ridx])
		ridx -= 1
		if (len(rq) >= k and rq[0] == a[0]):
			c = 1
			for i in range(k):
				if (rq[i] != a[i]):
					c = 0
					break
		if (c == 1):
			for i in range(k):
				rq.popleft()
			break

s = ''.join(lq) + ''.join(rq)

while (s.find(a) != -1):
	s = s[:s.find(a)] + s[s.find(a) + k:]
print(s)