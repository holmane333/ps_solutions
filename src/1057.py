from sys import stdin

count=1
a,b,c=map(int,stdin.readline().rstrip().split())

while True:
    if b==1 and c==1:
        print(count)
        break
    else:
        if b%2+b//2==c%2+c//2:
            print(count)
            break
        else:
            b=b%2+b//2
            c=c%2+c//2
            count+=1
