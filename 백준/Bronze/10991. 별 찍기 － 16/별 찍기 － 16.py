from sys import stdin
n=int(stdin.readline().rstrip())
for i in range(1,n+1):
    print(' '*(n-i),end='')
    print('* '*(i-1),end='')
    print('*')
