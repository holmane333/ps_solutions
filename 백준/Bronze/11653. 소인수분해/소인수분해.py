from sys import stdin
from math import sqrt
n=int(stdin.readline().rstrip())
n_1=n
i=2
while True:
    if n%i==0:
        print(i)
        n//=i
    else:
        i+=1
    if i>sqrt(n_1):
        break
if n!=1:
    print(n)
