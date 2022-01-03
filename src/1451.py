from sys import stdin

n,m=map(int,stdin.readline().split())
l1=[[0 for i in range(m+1)]]
l2=l1.copy()
l3=[]
l4=[[0,1,2,3],[0,2,1,3],[1,3,0,2],[2,3,0,1]]

for i in range(n):
    l1.append([0] + list(stdin.readline().rstrip()))
    l2.append([0 for j in range(m+1)])

for i in range(n+1):
    for j in range(m+1):
        l1[i][j]=int(l1[i][j])

for i in range(1,n+1):
    for j in range(1,m+1):
        l2[i][j]=l1[i][j]+l2[i-1][j]+l2[i][j-1]-l2[i-1][j-1]

max=-99999
count=0

for i in range(1,n+1):
    for j in range(1,m+1):
        a=l2[i][j]
        b=l2[n][j]-a
        c=l2[i][m]-a
        d=l2[n][m]-a-b-c
        # a=2, b=3, c=1, d=4
        l3=[a,b,c,d]
        for k in l4:
            count=(l3[k[0]]+l3[k[1]])*l3[k[2]]*l3[k[3]]
            if max<count:
                max=count
for i in range(1,n+1):
    for j in range(i+1,n+1):
        a=l2[i][m]
        b=l2[j][m]-a
        c=l2[n][m]-a-b
        count=a*b*c
        if max<count:
            max=count
for i in range(1,m+1):
    for j in range(i+1,m+1):
        a = l2[n][i]
        b = l2[n][j] - a
        c = l2[n][m] - a - b
        count=a*b*c
        if max<count:
            max=count
print(max)