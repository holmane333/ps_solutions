n=int(input())
count=1
n-=1
i=1
while n>0:
    n-=i*6
    count+=1
    i+=1
print(count)
