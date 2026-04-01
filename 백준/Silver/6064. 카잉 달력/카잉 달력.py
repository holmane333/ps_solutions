import sys
import math

testcase=int(sys.stdin.readline())
l=[]
for _ in range(testcase):
    m,n,x,y=map(int,sys.stdin.readline().split())
    a,b=x,x%n
    if b==0:
        b=n
    count=x
    while a!=x or b!=y:
        if m==x and n==y:
            count=m*n//math.gcd(m,n)
            break
        b=(b+m)%n
        if b==0:
            b=n
        count+=m
        if count>m*n:
            count=-1
            break
    l.append(count)
for j in range(testcase):
    print(l[j])