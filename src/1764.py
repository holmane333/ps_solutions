from sys import stdin

l1,l2=set(),set()
n,m=map(int,stdin.readline().rstrip().split())

for i in range(n):
    l1.add(stdin.readline().rstrip())
for j in range(m):
    l2.add(stdin.readline().rstrip())
result=l1&l2
result=list(result)
result.sort()
print(len(result))
print('\n'.join(result))
