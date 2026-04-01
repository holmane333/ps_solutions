T=int(input())
a=[]
for i in range(T):
    a.append(int(input()))
a.sort()
for j in range(T):
    print(a[j])