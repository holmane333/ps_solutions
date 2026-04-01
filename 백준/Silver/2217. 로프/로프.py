from sys import stdin
n=int(stdin.readline().rstrip())
l=[]
for i in range(n):
	l.append(int(stdin.readline().rstrip()))
l.sort(reverse=True)
result=l[0]
for i in range(1,n):
	count=l[i]*(i+1)
	if result<count:
		result=count
print(result)