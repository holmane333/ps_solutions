from sys import stdin
a=int(stdin.readline().rstrip())
k=0
while a!=0:
    a//=5
    k+=a
print(k)
