from sys import stdin
t=int(stdin.readline().rstrip())
l=[]
for i in range(t):
    l.append(int(stdin.readline().rstrip()))
l.sort()
count=1
countmax=0
num=l[0]
nummax=1
for i in range(1,t):
    if num==l[i]:
        count+=1
    else:
        if countmax<count:
            countmax=count
            nummax=l[i-1]
        num=l[i]
        count=1
if countmax<count:
    countmax=count
    nummax=l[i]
print(nummax)
