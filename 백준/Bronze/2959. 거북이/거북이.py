from sys import stdin
l=list(map(int,stdin.readline().rstrip().split()))
l.sort()
print(l[0]*l[2])
