from sys import stdin

n = int(stdin.readline())
s = []
for i in range(n):
	s.append((stdin.readline().rstrip())[2:])
s.sort()
#print(s)
for i in range(n):
	s[i] = s[i].split()
#print(s)
#print(*s, sep='\n')

t = [""]
for i in range(n):
	tt = t
	for j in range(len(s[i])):
		c = 0
		for k in range(1, len(tt)):
			if (tt[k][0] == s[i][j]):
				tt = tt[k]
				c = 1
		if (not c):
			tt.append([s[i][j]])
			tt = tt[-1]

def pr(t, sp):
	if (t == []):
		return
	if (t[0] != ""):
		print(sp, t[0], sep='')
	for i in range(1, len(t)):
		if (t[0] != ""):
			pr(t[i], sp + '--')
		else:
			pr(t[i], sp)

#print(*t, sep='\n')
pr(t, '')