from sys import stdin
n=int(stdin.readline().rstrip())
l=list(map(int,stdin.readline().rstrip().split()))
n-=1
a_1=l.pop(0)
a=a_1
for i in range(n):
    a=a_1
    b=l[i]
    b_1=b
    while b!=0:
        a,b=b,a%b
    print('%d/%d'%(a_1//a,b_1//a))