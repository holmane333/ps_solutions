from sys import stdin
n=int(stdin.readline().rstrip())
l=list(map(int,stdin.readline().rstrip().split()))
count=0
for i in l:
    if n==i:
        count+=1
print(count)
