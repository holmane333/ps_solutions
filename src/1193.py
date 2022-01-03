k=int(input())
n=0
for i in range(1,k+1):
    n+=i
    if k<=n:
        if i%2==0:
            t=n-k
            print('%s/%s'%(i-t,t+1))
        else:
            t=n-k
            print('%s/%s'%(t+1,i-t))
        break