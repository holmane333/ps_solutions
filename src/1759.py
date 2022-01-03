from sys import stdin

def bf(n,m,l):
    global l2
    l1=l.copy()
    for i in range(m-1,-1,-1):
        del l[i]
        if m-1==a:
            if l not in l2:
                l2.append(l)
            l = l1.copy()
        else:
            bf(n,m-1,l)
            l=l1.copy()
    return 0



l2=[]
l3=['a','e','i','o','u']
l4=[]
for i in range(26):
    l4.append("%c"%(97+i))
for i in range(5):
    l4.remove(l3[i])

a,b=map(int,stdin.readline().split())
l=list(map(str,stdin.readline().rstrip().split()))
l.sort()
if a==b:
    counta=0
    countb=0
    for i in l:
        if i in l3:
            counta+=1
        elif i in l4:
            countb+=1
    if counta>=1 and countb>=2:
        print(''.join(l))
bf(a,b,l)
for i in range(len(l2)):
    l2[i].sort()
l2.sort()
for i in range(len(l2)-1,-1,-1):
    counta=0
    countb=0
    for j in range(a):
        if l2[i][j] in l3:
            counta+=1
        elif l2[i][j] in l4:
            countb+=1
    if counta<1 or countb<2:
        del l2[i]
for j in l2:
    print(''.join(j))
