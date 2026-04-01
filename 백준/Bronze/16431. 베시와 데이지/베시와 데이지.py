from sys import stdin

a1,b1=map(int,stdin.readline().split())
a2,b2=map(int,stdin.readline().split())
a3,b3=map(int,stdin.readline().split())
n1=abs(a1-a3)
n2=abs(b1-b3)
m=abs(abs(a2-a3)+abs(b2-b3))
if n1>n2:
    n=n1
else:
    n=n2
if n>m:
    print('daisy')
elif n<m:
    print('bessie')
else:
    print('tie')
