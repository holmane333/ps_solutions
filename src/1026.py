from sys import stdin
t=int(stdin.readline().rstrip())
a=list(map(int,stdin.readline().rstrip().split()))
b=list(map(int,stdin.readline().rstrip().split()))
a.sort()
b.sort(reverse=True)
count=0
for i in range(t):
    count+=a[i]*b[i]
print(count)