from sys import stdin
def fact(x,y):
    t1=x-1
    t2=1
    while y>1:
        x*=t1
        t2*=y
        t1-=1
        y-=1
    x//=t2
    return x
a,b=map(int,stdin.readline().rstrip().split())
if b==0:
    print(1)
else:
    print(fact(a,b))
