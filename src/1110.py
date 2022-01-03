n=int(input())
a=n//10
b=n%10
c=1
a,b=b,a+b
if b>=10:
	b=b%10
while n!=10*a+b:
    a,b=b,a+b
    if b>=10:
    	b=b%10
    c+=1
print(c)