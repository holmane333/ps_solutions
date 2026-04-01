from sys import stdin
n=int(stdin.readline().rstrip())
a=1
b=2
if n==1:
    print(a)
elif n==2:
    print(b)
else:
    for i in range(n-2):
        a,b=b,a+b
        b%=10007
    print(b)
