from sys import stdin

n,m=map(int,stdin.readline().split())
l=[]
for i in range(n):
    l.append(list(map(int,stdin.readline().split())))
max_n=0
for i in range(m):
    for j in range(i+1,m):
        for k in range(j+1,m):
            sum=0
            for a in range(n):
                sum+=max(l[a][i],max(l[a][j],l[a][k]))
            if max_n<sum:
                max_n=sum
print(max_n)
