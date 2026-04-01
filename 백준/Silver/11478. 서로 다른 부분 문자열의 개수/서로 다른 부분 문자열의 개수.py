from sys import stdin

s = stdin.readline().rstrip()
l = len(s) + 1
d = {}
for i in range(l):
	for j in range(i + 1, l):
		d[s[i:j]] = 1
print(len(d))
#print(d)