from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
l=[]
while True:
    if a%b>=10:
            l.append('%c'%(a%b+55))
    else:
            l.append(str(a%b))
    if a//b==0:
        break
    a//=b
l.reverse()
print(''.join(l))