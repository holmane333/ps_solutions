import math
n=list(input())
k=[0 for i in range(10)]
for i in range(0,10):
    k[i]=(n.count('%s'%i))
k[6]=math.ceil((k[6]+k[9])/2)
k[9]=0
print(max(k))
