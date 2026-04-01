from sys import stdin
n=int(stdin.readline().rstrip())
a=1
b=1
if n==1 or n==2:
    print(1)
else:
    for i in range(n-2):
        a,b=b,a+b
    print(b)
