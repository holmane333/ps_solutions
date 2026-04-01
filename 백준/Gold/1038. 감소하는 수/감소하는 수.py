n = int(input())
global l
l = []

def dfs(num, d):
	l.append(num)
	for i in range(d - 1, -1, -1):
		dfs(num * 10 + i, i)

for i in range(9, -1, -1):
	dfs(i, i)

l.sort()
if (n >= 1023):
	print(-1)
else:
	print(l[n])