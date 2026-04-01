from sys import stdin
n=1000-int(stdin.readline().rstrip())
count=0
l=[500,100,50,10,5,1]
for i in range(6):
    if n//l[i]!=0:
        count+=n//l[i]
        n%=l[i]
print(count)
