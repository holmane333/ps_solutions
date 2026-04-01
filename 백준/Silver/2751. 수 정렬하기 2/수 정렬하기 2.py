from sys import stdin
T=int(stdin.readline())
a=[]
for i in range(T):
    a.append(int(stdin.readline()))
a.sort()
for j in range(T):
    print(a[j])