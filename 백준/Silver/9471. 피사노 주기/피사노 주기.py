from sys import stdin
for i in range(1,int(stdin.readline().rstrip())+1):
    m,n=map(int,stdin.readline().rstrip().split())
    a=1
    b=1
    count=0
    while True:
        count+=1
        a,b=b%n,(a+b)%n
        if a==1 and b==1:
            break
    print(i,count)
