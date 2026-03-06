from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
l=[]
count=0
for i in range(a):
    l.append(int(stdin.readline().rstrip()))
for i in range(a):
    count+=b//l[-1]
    b%=l[-1]
    del l[-1]
    if b==0:
        break
print(count)
