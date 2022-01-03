from sys import stdin
n=int(stdin.readline().rstrip())
l=[]
for i in range(n):
    l.append(list(map(int,stdin.readline().rstrip().split())))
l.sort(key=lambda x:x[0])
l.sort(key = lambda x:x[1])
count=1
k=l[0]
for i in range(1,len(l)):
    if k[1]>l[i][1]:
        k=l[i][:]
    elif k[1]<=l[i][0]:
        k=l[i][:]
        count+=1
print(count)