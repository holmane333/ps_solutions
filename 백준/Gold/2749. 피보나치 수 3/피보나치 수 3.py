from sys import stdin
n=int(stdin.readline().rstrip())
a=1
b=1
l=[0,1,1]
if n==1 or n==2:
    print(1)
else:
    for i in range(1499997):
        a,b=b,(a+b)%1000000
        l.append(b)
    print(l[n%1500000])
