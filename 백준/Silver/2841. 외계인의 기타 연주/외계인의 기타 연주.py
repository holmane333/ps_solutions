from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
l1=[]
l2=[]
count=0
for i in range(a):
    n,m=map(int,stdin.readline().rstrip().split())
    if n not in l1:
        l1.append(n)
        l2.append([m])
        count+=1
    else:
        w=l2[l1.index(n)]
        c=0
        for j in range(len(w)):
            if w[j]>m:
                count+=len(w)-j+1
                w=w[:j]
                w.append(m)
                c=1
                break
            elif w[j]==m:
                count+=len(w)-j-1
                w=w[:j+1]
                c=1
                break
        if c==0:
            count+=1
            w.append(m)
        l2[l1.index(n)]=w
print(count)
