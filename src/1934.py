from sys import stdin
testcase=int(stdin.readline().rstrip())
l=[]
for i in range(testcase):
    a,b=map(int,stdin.readline().rstrip().split())
    if b<a:
        a,b=b,a
    ab=a*b
    while b!=0:
        a,b=b,a%b
    l.append(ab//a)
for i in l:
    print(i)