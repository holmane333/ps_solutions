from sys import stdin
n=int(stdin.readline().rstrip())
k=[]
for i in range(n):
    k.append(stdin.readline().rstrip())
k=set(k)
k=list(k)
k.sort()
k.sort(key=len)
for i in k:
    print(i)
