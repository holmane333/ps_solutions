from itertools import permutations
from sys import stdin
n=int(stdin.readline().rstrip())
l=map(int,stdin.readline().rstrip().split())
k=[]
for p in permutations(l):
    count=0
    for i in range(len(p)-1):
        count+=abs(p[i]-p[i+1])
    k.append(count)
print(max(k))
