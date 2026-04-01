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
while True:
    a,b=map(int,stdin.readline().rstrip().split())
    if a==0 and b==0:
        break
    elif b==0 or a==b:
        print(1)
    else:
        if a-b<b:
            b=a-b
        print(fact(a,b))