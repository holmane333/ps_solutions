from sys import stdin
t=int(stdin.readline().rstrip())
l=[]
for i in range(t):
    n=int(stdin.readline().rstrip())
    if n%2==0:
        l.append('even')
    else:
        l.append('odd')
for i in range(t):
    print(l[i])
