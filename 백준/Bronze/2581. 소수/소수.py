a=int(input())
b=int(input())
if a==1:
    a+=1
f=[_ for _ in range(a,b+1)]
for j in range(a,b+1):
    for i in range(2,b+1):
        if j%i==0:
            if j==i:
                continue
            else:
                f.remove(j)
                break
if len(f)==0:
    print(-1)
else:
    print(sum(f))
    print(f[0])