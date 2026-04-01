from sys import stdin
import heapq

n = int(stdin.readline())

l = [0 for i in range(n + 1)]
l[1] = 1
for i in range(2, n + 1):
	l[i], l[i - 1] = 1, i
	k = i - 1
	while(k > 1):
		l[k], l[k // 2] = l[k // 2], l[k]
		k //= 2

del l[0]

for i in range(n):
	l[i] = str(l[i])
print(" ".join(l))