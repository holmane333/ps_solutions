t=int(input())
result=[]
for _ in range(t):
        l1=list(map(int,input().split()))
        l2=[0,0,0,0,0,0]
        l1.sort()
        for i in l1:
                l2[i-1]+=1
        if 4 in l2:
                result.append(50000+5000*(l1[0]))
        elif 3 in l2:
                result.append(10000+1000*(l2.index(3)+1))
        elif 2 in l2:
                if l2.count(2)==2:
                        k=l2.index(2)
                        l2.pop(k)
                        result.append(2000+500*(k+l2.index(2)+3))
                else:
                        result.append(1000+100*(l2.index(2)+1))
        else:
                result.append(100*(l1[3]))
result.sort()
print(result[t-1])