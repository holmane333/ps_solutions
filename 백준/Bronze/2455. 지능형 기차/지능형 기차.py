from sys import stdin

count=0
result=0
for i in range(4):
    a,b=map(int,stdin.readline().rstrip().split())
    count+=b-a
    if result<count:
        result=count
print(result)