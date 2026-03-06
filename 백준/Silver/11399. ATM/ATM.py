from sys import stdin
n=int(stdin.readline().rstrip())
l=list(map(int,stdin.readline().rstrip().split()))
l.sort()
count=0
for i in range(n):
    count+=l[i]*(n-i)
print(count)
