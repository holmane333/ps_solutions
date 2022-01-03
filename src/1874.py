from sys import stdin
a=int(stdin.readline().rstrip())
l=[i for i in range(1,a+1)]
w=[]
result=[]
pop1=[]
k=[]
for i in range(a):
    w.append(int(stdin.readline().rstrip()))
for i in range(a):
    if w[i] not in result:
        while True:
            result.append(l.pop(0))
            k.append('+')
            if result[-1]==w[i]:
                break
        result.pop(-1)
        k.append('-')
    else:
        if result[-1]!=w[i]:
            print('NO')
            break
        else:
            result.pop(-1)
            k.append('-')
if k.count('-')==a:
    for i in range(len(k)):
        print(k[i])
