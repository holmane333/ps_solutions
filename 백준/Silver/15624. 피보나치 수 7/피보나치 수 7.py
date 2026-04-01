from sys import stdin
n=int(stdin.readline().rstrip())
a=0
b=1
if (n == 0):
	print(0)
else:
    for i in range(n - 1):
        a,b=b,(a+b)%1000000007
    print(b)
