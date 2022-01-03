from sys import stdin

n1=int(stdin.readline())
n2=n1
n3=abs(n1-100)
num=int(stdin.readline())
l=['0','1','2','3','4','5','6','7','8','9']
if num>0:
    l1=list(map(int,stdin.readline().split()))
else:
    l1=[]
l1.sort()
for i in range(num-1,-1,-1):
    del l[l1[i]]
count=0

if num==10:
    print(n3)
else:
    t=0
    while True:
        c=1
        n1,n2=str(n1),str(n2)
        for i in range(len(n2)):
            if t==1:
                break
            if n2[i] not in l:
                c=0
                break
        if c!=0 and t==0:
            c=2
            break
        c=1
        for i in range(len(n1)):
            if n1[i] not in l:
                c=0
                break
        if c==1:
            break
        
        else:
            n1=int(n1)+1
            n2=int(n2)-1
            if n2<0:
                n2=0
                t=1
        count+=1

    if c==1:
        count+=len(str(n1))
    else:
        count+=len(str(n2))
    if count>n3:
        count=n3
    print(count)
