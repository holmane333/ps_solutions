from sys import stdin


l=[1,2,3]
n=int(stdin.readline().rstrip())
for i in range(n):
    x,y=map(int,stdin.readline().rstrip().split())
    k1=l.index(x)
    k2=l.index(y)
    l[k1],l[k2]=y,x

print(l[0])
