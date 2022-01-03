from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
if b<a:
    a,b=b,a
ab=a*b
while b!=0:
    a,b=b,a%b
print('1'*a)