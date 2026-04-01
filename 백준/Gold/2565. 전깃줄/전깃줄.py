from sys import stdin

idx1=-1
idx2=-1
def DP(n):
    result=1
    x=l[n][1]
    for i in range(n):
        if ((x>=l[i][1])and(result<=dp[i])):
            result=dp[i]+1
    dp[n]=result
    return result


n=int(stdin.readline().rstrip())
l=[[0,0]]
for i in range(n):
    a,b=map(int,stdin.readline().rstrip().split())
    l.append([a,b])
l.sort(key=lambda x:x[0])
dp=[0 for i in range(n+1)]
max=0
for i in range(1,n+1):
    result=DP(i)
    if (max<result):
        max=result
print("%d"%(n-max))