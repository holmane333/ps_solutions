from sys import stdin

n=int(stdin.readline().rstrip())
str1=""
if n==1:
    print(1)
elif n==0:
    print(0)
else:
    while True:
        if n==1:
            break
        str1+=str(n%2)
        n=n//-2+n%2
    str1+="1"
    for i in range(len(str1)-1,-1,-1):
        print(str1[i],end='')
