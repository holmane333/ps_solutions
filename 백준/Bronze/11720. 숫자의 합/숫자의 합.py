t=input()
a=str(input())
b=[]
i=0
while i<len(a):
    b.append(int(a[i]))
    i=i+1
j=0
for c in b:
   j+=c
print(j)