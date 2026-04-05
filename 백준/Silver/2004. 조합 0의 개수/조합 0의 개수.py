from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
a_1,b_1=a,b
result2=0
result5=0
if a==b:
    print(0)
else:
    while True:
        if a//2!=0:
            result2+=a//2
            a//=2
        else:
            break
    a=a_1
    while True:
        if a//5!=0:
            result5+=a//5
            a//=5
        else:
            break
    while True:
        if b//2!=0:
            result2-=b//2
            b//=2
        else:
            break
    b=b_1
    while True:
        if b//5!=0:
            result5-=b//5
            b//=5
        else:
            break
    b=a_1-b_1
    while True:
        if b//2!=0:
            result2-=b//2
            b//=2
        else:
            break
    b=a_1-b_1
    while True:
        if b//5!=0:
            result5-=b//5
            b//=5
        else:
            break
    if result2>result5:
        print(result5)
    else:
        print(result2)
