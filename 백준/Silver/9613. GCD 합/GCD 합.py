from sys import stdin
def gcd(a,b):
    while True:
        if b==0:
            break
        a,b=b,a%b
    return a
for i in range(int(stdin.readline().rstrip())):
    l=list(map(int,stdin.readline().rstrip().split()))
    t=l.pop(0)
    count=0
    for j in range(t-1):
        for k in range(1,t-j):
            count+=gcd(l[0],l[k])
        del l[0]
    print(count)
