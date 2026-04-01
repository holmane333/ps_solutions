from sys import stdin
import math
n=int(stdin.readline().rstrip())
l=list(map(int,stdin.readline().rstrip().split()))
a,b=map(int,stdin.readline().rstrip().split())
count=0
for i in range(n):
    l[i]-=a
    count+=1
    if math.ceil(l[i]/b)>0:
        count+=math.ceil(l[i]/b)
        l[i]//=b
print(count)
