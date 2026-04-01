from sys import stdin
n=int(stdin.readline().rstrip())
for i in range(n):
    print(' '*(n-i-1),end='')
    print('*'*(2*i+1))
