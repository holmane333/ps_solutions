a=list(map(int,input().split()))
b=sorted(a)
c=list(b)
c.reverse()
if a==b:
    print('ascending')
elif a==c:
    print('descending')
else:
    print('mixed')