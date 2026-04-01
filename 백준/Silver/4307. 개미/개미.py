from sys import stdin
n=int(stdin.readline().rstrip())
for _ in range(n):
    a,b=map(int,stdin.readline().rstrip().split())
    l=[[],[]]
    for i in range(b):
        k=int(stdin.readline().rstrip())
        if k<a-k:
            l[0].append(k)
            l[1].append(a-k)
        else:
            l[1].append(k)
            l[0].append(a-k)
    print(max(l[0]),max(l[1]))
