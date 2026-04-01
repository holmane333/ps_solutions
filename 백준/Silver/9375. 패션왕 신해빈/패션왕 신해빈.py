from sys import stdin

testcase=int(stdin.readline().rstrip())
result=[]
for _ in range(testcase):
    result_n=1
    n=int(stdin.readline().rstrip())
    l=[]
    for j in range(n):
        k=stdin.readline().rstrip()
        l.append(k[k.index(' ')+1:])
    l.sort()
    count=[]
    while len(l)!=0:
        t=l.count(l[0])
        count.append(t+1)
        for i in range(t):
            del l[0]
    for i in count:
        result_n*=i
    result.append(result_n-1)
for j in range(testcase):
    print(result[j])
