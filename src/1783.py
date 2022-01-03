from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
if a==1 or b==1:
    print(1)
elif a==2:
    print(min(4,(b+1)//2))
elif b==2:
    print(2)
elif b==3:
    print(3)
elif b==4 or b==5 or b==6:
    print(4)
else:
    print(b-2)