from sys import stdin
import math
a,b=map(int,stdin.readline().rstrip().split())
l_1=[]
l_2=[]
for i in range(b):
    n,m=map(int,stdin.readline().rstrip().split())
    l_1.append(n)
    l_2.append(m)
l_1.sort()
l_2.sort()
count_1=l_1[0]*(math.ceil(a/6))
count_2=l_1[0]*(a//6)+l_2[0]*(a%6)
count_3=l_2[0]*a
if count_1<=count_2 and count_1<=count_3:
    print(count_1)
elif count_2<=count_3:
    print(count_2)
else:
    print(count_3)

