from sys import stdin
def sosu(l,n,result):
    for i in range(2,n+1):
        if l[i]==1:
            result.append(i)
            for j in range(2*i,n+1,i):
                l[j]=0
    return result

for i in range(int(stdin.readline().rstrip())):
    a=int(stdin.readline().rstrip())
    l=[0,0]+[1]*(a-1)
    result=[]
    result=sosu(l,a,result)
    c=[]
    for i in range((len(result))):
        if result[i]>a//2:
            break
        if a-result[i] in result:
            c.append([result[i],a-result[i],abs(result[i]-a+result[i])])
    c.sort(key=lambda x:x[2])
    print('%d %d'%(c[0][0],c[0][1]))
