from sys import stdin
def sosu(l,n,result):
    for i in range(2,n+1):
        if l[i]==1:
            result.append(i)
            for j in range(2*i,n+1,i):
                l[j]=0
    return result
a,b=map(int,stdin.readline().rstrip().split())
l1=[0,0]+[1]*(a-1)
l2=[0,0]+[1]*(b-1)
result1=[]
result2=[]
result1=sosu(l1,a,result1)
result2=sosu(l2,b,result2)
for i in range(len(result1)):
    del result2[0]
if a!=1:
    if result1[-1]==a:
        result2.insert(0,a)
for i in result2:
    print(i)
