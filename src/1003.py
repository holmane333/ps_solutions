from sys import stdin
t=int(stdin.readline().rstrip())
l=[]
for i in range(t):
    a=0
    b=1
    c=1
    d=0
    n=int(stdin.readline().rstrip())
    if n==0:
        l.append('%d %d'%(b,a))
    elif n==1:
        l.append('%d %d'%(d,c))
    else:
        for i in range(n-1):
            a,b,c,d=c,d,a+c,b+d
        l.append('%d %d'%(d,c))
for i in range(t):
    print(l[i])
