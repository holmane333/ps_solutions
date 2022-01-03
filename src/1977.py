from sys import stdin
import math
a=int(stdin.readline().rstrip())
b=int(stdin.readline().rstrip())
a=math.ceil(math.sqrt(a))
b=int(math.sqrt(b))
r1=0
if b-a<=0:
    print(-1)
else:
    for i in range(b,a-1,-1):
        r1+=i**2
    print(r1)
    print(i**2)