a=0
t=int(input())
def x(n):
	if n not in range(100):
		s=list(map(int,str(n)))
		d=s[1]-s[0]
		for i in range(len(s)-1):
			if not s[i+1]-s[i]==d:
				return False
		return True
	else:
		return True
for j in range(1,t+1):
	if x(j):
		a+=1
print(a)