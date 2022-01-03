from sys import stdin
testcase=int(stdin.readline().rstrip())
result=[]
for i in range(testcase):
    l=[]
    n,a=map(int,stdin.readline().rstrip().split())
    k_1=list(map(int,stdin.readline().rstrip().split()))
    k_2=[i for i in range(n)]
    l.append(k_1)
    l.append(k_2)
    count=0
    while True:
        if l[0][0]!=max(l[0]):
            l[0].append(l[0][0])
            del l[0][0]
            l[1].append(l[1][0])
            del l[1][0]
        else:
            if a==l[1][0]:
                count+=1
                break
            else:
                del l[0][0]
                del l[1][0]
                count+=1
    result.append(count)
for i in result:
    print(i)
