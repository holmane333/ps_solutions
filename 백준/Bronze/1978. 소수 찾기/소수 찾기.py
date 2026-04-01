T=int(input())
a=list(map(int,input().split()))
if 1 in a:
    a.remove(1)
    T-=1
m=max(a)
x=0
for j in a:
    for i in range(2,m+1):
        if j%i==0:
            if j==i:
                continue
            else:
                T-=1
                break
print(T)