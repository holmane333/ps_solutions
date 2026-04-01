from sys import stdin
n=int(stdin.readline().rstrip())
for i in range(1,n+1):
    if i==1:
        print(' '*(n-i),end='')
        print('*')
    elif i!=n:
        print(' '*(n-i),end='')
        print('*',end='')
        print(' '*(2*i-3),end='')
        print('*')
    else:
        print('*'*(2*i-1))
