from sys import stdin
l=list(stdin.readline().rstrip())
for i in range(len(l)):
    l[i]=int(l[i])
count=0
result=len(l)
if l[0]==1:
    for i in range(1,len(l)-1):
        if l[i]<1:
            result-=1
            count=1
            break
        elif l[i]>1:
            count=1
            break
    if count==0:
        if l[-1]==0:
            result-=1
    print(result)
else:
    print(result)
