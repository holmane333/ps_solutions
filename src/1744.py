from sys import stdin
n=int(stdin.readline().rstrip())
l1=[]
l2=[]
l3=[]
l4=[]
for i in range(n):
    t=int(stdin.readline().rstrip())
    if t<0:
        l1.append(t)
    elif t==0:
        l2.append(t)
    elif t==1:
        l4.append(t)
    else:
        l3.append(t)
l1.sort()
l3.sort()
count=0
k=len(l3)
if len(l3)%2==0:
    for i in range(0,k,2):
        count+=l3[i]*l3[i+1]
else:
    for i in range(1,k,2):
        count+=l3[i]*l3[i+1]
    count+=l3[0]
if len(l1)!=0:
    k=len(l1)
    if k%2==0:
        for i in range(0,k,2):
            count+=l1[i]*l1[i+1]
    else:
        for i in range(0,k-1,2):
            count+=l1[i]*l1[i+1]
        if len(l2)==0:
            count+=l1[-1]
for i in range(len(l4)):
    count+=1
print(count)