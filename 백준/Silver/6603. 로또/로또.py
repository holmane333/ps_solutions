from sys import stdin

def bf(n,l,k):
    global l1,l2
    l3=l.copy()
    for i in range(k-1,-1,-1):
        del l[i]
        if n-1==6:
            if l not in l2:
                l2.append(l)
            l = l3.copy()
        else:
            bf(n-1,l,i)
            l=l3.copy()
    return 0



l2=[]
l_1=[0,1,2,3,4,5,6]
l_a=[]
l1=l_1.copy()
for j in range(6):
    bf(7+j,l_1,7+j)
    l2.sort()
    l_a.append(l2)
    l2=[]
    l1.append(7+j)
    l_1=l1.copy()

while True:
    str1=stdin.readline().rstrip()
    if str1=='0':
        break
    l=list(map(str,str1.split()))
    n=int(l.pop(0))
    for i in l_a[n-7]:
        for j in range(6):
            print(l[i[j]],end='')
            if j!=5:
                print(' ',end='')
        print()
    print()
