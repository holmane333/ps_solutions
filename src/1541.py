from sys import stdin

l=list(map(str,stdin.readline().rstrip().split('-')))
for i in range(len(l)):
    try:
        l[i]=eval(l[i])
    except SyntaxError:
        l1=list(map(int,l[i].split('+')))
        a=0
        for j in l1:
            a+=j
        l[i]=a
result=l[0]
for i in range(1,len(l)):
    result-=l[i]
print(result)
