from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
l=list(map(int,stdin.readline().rstrip().split()))
l.sort()
print(l[b-1])
