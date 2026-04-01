a=int(input())
b=int(input())
c=int(input())
s=list()
result=str(a*b*c)
for x in range(len(result)):
    s.append(int(result[x]))
for i in range(10):
    print('%d'%(s.count(i)))