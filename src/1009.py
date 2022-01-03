import sys

testcase=int(input())
for i in range(testcase):
	a,b=map(int,sys.stdin.readline().rstrip().split())
	a%=10
	if a in [1,5,6]:
		b=1
	elif a in [2,3,7,8]:
		if b%4==0:
			b=4
		else:
			b%=4
	elif a in [4,9]:
		if b%2==0:
			b=2
		else:
			b%=2
	if b==0:
		c=a%10
	else:
		c=(a**b)%10
	if c==0:
		print(10)
	else:
		print(c)