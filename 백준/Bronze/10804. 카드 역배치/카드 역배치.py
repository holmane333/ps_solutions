from sys import stdin
l=[str(i) for i in range(1,21)]
for i in range(10):
    a,b=map(int,stdin.readline().rstrip().split())
    l_1=l[a-1:b]
    l_1.reverse()
    for j in range(a-1,b):
        l[j]=l_1[j-a+1]
print(' '.join(l))
