from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
l=[i for i in range(1,a+1)]
w=list(map(int,stdin.readline().rstrip().split()))
count=0
for i in range(b):
    n=l.index(w[i])
    if len(l)-n>=n:
        l=l[n+1:]+l[:n]
        count+=n
    else:
        l=l[n+1:]+l[:n]
        count+=len(l)-n+1
print(count)
