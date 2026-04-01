from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
l1=list(map(int,stdin.readline().rstrip().split()))
l2=list(map(int,stdin.readline().rstrip().split()))
l3=l1+l2
l3.sort()
for i in l3:
    print(i,end=' ')
