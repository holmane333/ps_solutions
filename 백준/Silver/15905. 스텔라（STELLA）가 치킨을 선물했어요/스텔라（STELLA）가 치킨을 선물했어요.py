from sys import stdin
n=int(stdin.readline().rstrip())
l=[]
for i in range(n):
	l.append(tuple(map(int,stdin.readline().rstrip().split())))
l.sort(key=lambda x:x[1])
l.sort(key=lambda x:x[0],reverse=True)
count=0
if n==5:
	print(count)
else:
	for i in range(n-5):
		if l[4][0]==l[5+i][0]:
			count+=1
		else:
			break
	print(count)