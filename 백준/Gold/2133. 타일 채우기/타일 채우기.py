from sys import stdin

n=int(stdin.readline().rstrip())
l=[0,0,3,0,11]
if n%2==1:
    print(0)
elif n==2:
    print(3)
elif n==4:
    print(11)
else:
    for i in range(5,n+1):
        if i%2==1:
            l.append(0)
        else:
            a=0
            for j in range(i//2-1):
                a+=l[2*j]*2
            a+=l[i-2]*3
            a+=2
            l.append(a)
    print(l[-1])