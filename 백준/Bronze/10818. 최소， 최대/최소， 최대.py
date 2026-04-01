from sys import stdin
t=int(stdin.readline().rstrip())
l=list(map(int,stdin.readline().rstrip().split()))
print(min(l),max(l))
