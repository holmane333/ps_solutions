from sys import stdin
from math import ceil
a,b,c=map(int,stdin.readline().rstrip().split())
if a//2>b:
    count=b
else:
    count=a//2
while c>0:
    if a==0 or b==0 or a==1:
        count=0
        break
    if a%2==1:
        c-=1
        a-=1
    if c==0:
        break
    if a//2>b:
        c-=(a//2-b)*2
        a=2*b
    elif a//2<b:
        c-=(b-a//2)
        b=a//2
    else:
        count-=ceil(c/3)
        c=0
print(count)
