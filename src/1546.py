q=int(input())
a=list(map(float,input().split()))
b=[]
m=max(a)
for i in range(0,q):
    b.append(a[i]*100/m)
print('%0.2f'%(sum(b)/q))