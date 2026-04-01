testcase=int(input())
l=[]
for i in range(testcase):
    a,b,c=map(int,input().split())
    if c%a==0:
        r=c//a-1
        c=a
    else:
        r=c//a
        c%=a
    l.append('%d%0.2d'%(c,r+1))
for i in range(testcase):
    print(l[i])
