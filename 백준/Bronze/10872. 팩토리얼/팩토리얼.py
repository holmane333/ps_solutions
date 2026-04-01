from sys import stdin

def fact(x):
    for i in range(1,x):
        x*=i
    return x

a=int(stdin.readline().rstrip())
if a==0:
    print(1)
else:
    print(fact(a))
