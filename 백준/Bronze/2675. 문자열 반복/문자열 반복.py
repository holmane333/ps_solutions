T=int(input())
for x in range(T):
    a=list(map(str,input().split()))
    b=int(a[0])
    c=list(str(a[1]))
    for i in range(len(c)-1,-1,-1):
        for j in range(1,b):
            c.insert(i,c[i])
    print(''.join(c))