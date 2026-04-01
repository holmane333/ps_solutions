(q,p)=map(int,input().split())
a=list(map(int,input().split()))
b=[]
i=0
while i<len(a):
    if a[i]<p:
       b.append(a[i])
    i+=1
print(' '.join(map(str,b)))