from sys import stdin

for _ in range(int(stdin.readline().rstrip())):
    n=int(stdin.readline().rstrip())
    l=[]
    for i in range(n):
        l.append(list(map(int,stdin.readline().rstrip().split())))
    l.sort()
    result=0
    min=100001
    for i in range(n):
        if min>l[i][1]:
            min=l[i][1]
            result+=1
    print(result)
