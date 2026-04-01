a=int(input())
b=0
while a>0:
	if a%5==0:
		b+=a//5
		a=0
	else:
		b+=1
		a-=3
if a<0:
	print(-1)
else:
	print(b)