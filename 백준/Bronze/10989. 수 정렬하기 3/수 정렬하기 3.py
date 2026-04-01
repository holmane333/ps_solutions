from sys import stdin
T=int(input())
m=10001
a=[0]*m
for i in range(T):
    a[int(stdin.readline())]+=1
for j in range(m):
    for x in range(a[j]):
        print(j)