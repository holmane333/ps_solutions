t=int(input())
a=list(map(int,input().split()))
a=sorted(a)
b=a[0]*a[t-1]
print(b)