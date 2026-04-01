from sys import stdin

def app(n,m):
    global a,dp, l1, l2
    if n>=100:
        return 0
    if n==a:
        return 0
    t=dp[n][m]
    if t!=-1:
        return t

    t=app(n+1,m)
    dp[n][m]=t

    if (m>=l2[n]):
        t=max(t,l1[n]+app(n+1,m-l2[n]))
        dp[n][m]=t
    return t

a,b=map(int,stdin.readline().split())
dp=[[-1 for i in range(12345)]for i in range(123)]
if a==1:
    l1=[int(stdin.readline())]
    l2=[int(stdin.readline())]
else:
    l1=list(map(int,stdin.readline().split()))
    l2=list(map(int,stdin.readline().split()))
l1.extend([0 for i in range(100)])
l2.extend([0 for i in range(100)])
i=0
while True:
    if app(0,i)>=b:
        print(i)
        break
    i+=1