from sys import stdin
import math

n,a=map(int,stdin.readline().split())
hp=1
max=1
for i in range(n):
    x,y,z=map(int,stdin.readline().split())
    if x==1:
        hp+=z//a*y
        if z%a==0:
            hp-=y
    else:
        a+=y
        if hp-z<=1:
            hp=1
        else:
            hp-=z
    if hp>max:
        max=hp
print(max)
