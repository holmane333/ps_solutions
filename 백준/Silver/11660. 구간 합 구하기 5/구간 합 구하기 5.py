from sys import stdin

n,m=map(int,stdin.readline().split())
l1=[[0 for i in range(n+1)]]
l2=l1.copy()

for i in range(n):
    l1.append([0] + list(map(int,stdin.readline().split())))
    l2.append([0 for j in range(n+1)])

for i in range(1,n+1):
    for j in range(1,n+1):
        l2[i][j]=l1[i][j]+l2[i-1][j]+l2[i][j-1]-l2[i-1][j-1]

for i in range(m):
    a,b,c,d=map(int,stdin.readline().split())
    print(l2[c][d]-l2[c][b-1]-l2[a-1][d]+l2[a-1][b-1])
