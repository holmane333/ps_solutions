from sys import stdin
a,b=map(int,stdin.readline().split())
if b-45<0:
    if a-1<0:
        print('%d %d'%(23,b+15))
    else:
        print('%d %d'%(a-1,b+15))
else:
    print('%d %d'%(a,b-45))
