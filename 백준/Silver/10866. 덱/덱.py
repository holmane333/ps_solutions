from sys import stdin
testcase=int(stdin.readline().rstrip())
l=[]
for i in range(testcase):
    a=stdin.readline().rstrip()
    if a=='pop_front':
        if len(l)==0:
            print(-1)
        else:
            print(l.pop(0))
    elif a=='pop_back':
        if len(l)==0:
            print(-1)
        else:
            print(l.pop(-1))
    elif a=='size':
        print(len(l))
    elif a=='empty':
        if len(l)==0:
            print(1)
        else:
            print(0)
    elif a=='front':
        if len(l)==0:
            print(-1)
        else:
            print(l[0])
    elif a=='back':
        if len(l)==0:
            print(-1)
        else:
            print(l[-1])
    else:
        if a[5:6]=='f':
            l.insert(0,a[a.index(' ')+1:])
        else:
            l.append(a[a.index(' ')+1:])

