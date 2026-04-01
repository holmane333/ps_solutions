from sys import stdin

l=[]
r1=0
r2=0
r3=0
r4=0
for i in range(int(stdin.readline().rstrip())):
    l.append(int(stdin.readline().rstrip()))
l.sort()
for i in l:
    r1+=i
r1/=len(l)
r2=l[len(l)//2+len(l)%2-1]
count=1
countmax=1
result=[]
for i in range(len(l)-1):
    if l[i]==l[i+1]:
        count+=1
    else:
        if countmax<count:
            countmax=count
            result=[l[i]]
            count=1
        elif countmax==count:
            result.append(l[i])
            count=1
        else:
            count=1
if countmax<count:
    countmax=count
    result=[l[-1]]
elif countmax==count:
    result.append(l[-1])
if len(l)==1:
    result.append(l[0])
if len(result)==1:
    r3=result[0]
else:
    r3=result[1]
r4=l[-1]-l[0]
print('%d\n%d\n%d\n%d'%(round(r1),r2,r3,r4))