from sys import stdin
a,b=map(int,stdin.readline().rstrip().split())
n=int(stdin.readline().rstrip())
l=list(map(int,stdin.readline().rstrip().split()))
count=0
l.reverse()
result=[]
for i in range(n):
    count+=l[i]*(a**i)
while True:
    result.append(str(count%b))
    if count//b==0:
        break
    count//=b
result.reverse()
print(' '.join(result))