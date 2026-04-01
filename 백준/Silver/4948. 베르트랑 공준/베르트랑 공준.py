from sys import stdin
def sosu(l,n,result):
    for i in range(2,n+1):
        if l[i]==1:
            result.append(i)
            for j in range(2*i,n+1,i):
                l[j]=0
    return result
while True:
    a=int(stdin.readline().rstrip())
    if a==0:
        break
    b=a*2
    l1=[0,0]+[1]*(a-1)
    l2=[0,0]+[1]*(b-1)
    result1=[]
    result2=[]
    result1=sosu(l1,a,result1)
    result2=sosu(l2,b,result2)
    for i in range(len(result1)):
        del result2[0]
    print(len(result2))
