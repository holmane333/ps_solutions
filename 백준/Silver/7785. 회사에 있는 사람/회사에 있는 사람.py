from sys import stdin

n = int(stdin.readline())
d = {}
l = []
for i in range(n):
	a, b = map(str, stdin.readline().split())
	if (b == "enter"):
		d[a] = 1
		l.append(a)
	else:
		d[a] = 0
l = list(set(l))
l.sort(reverse=True)
ans = []
for i in l:
	if(d[i]):
		ans.append(i)
print(*ans, sep='\n')