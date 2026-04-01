t=int(input())
for x in range(t):
    a=list(map(int,input().split()))
    b=[]
    p=a.pop(0)
    s=sum(a)/p
    for i in range(p):
        if a[i]>s:
            b.append(a[i])
    print('%0.3f'%(len(b)/p*100)+'%')