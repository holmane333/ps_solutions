from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
l=[[i+1 for i in range(a)],[1 for i in range(a)]]
count=0
result=[]
i=0
while True:
    while True:
        if l[1][i]==1:
            count+=1
        if count==b:
            count=0
            break
        i+=1
        i%=a
    result.append(str(l[0][i]))
    l[1][i]=0
    if len(result)==a:
        break
print('<%s>'%(', '.join(result)))
