a=str(input())
def f():
    if len(a)%10==0:
       return len(a)//10
    else:
       return (len(a)//10)+1
i=1
while i<=f():
    print(a[10*(i-1):10*i])
    i=i+1