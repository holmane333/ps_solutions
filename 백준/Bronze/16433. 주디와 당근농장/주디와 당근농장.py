from sys import stdin

n,a,b=map(int,stdin.readline().split())
if abs(a-b)%2:
    for i in range(1,n+1):
        for j in range(1,n+1):
            if (i+j)%2:
                print('v',end='')
            else:
                print('.',end='')
        print('')
else:
    for i in range(1,n+1):
        for j in range(1,n+1):
            if (i+j)%2:
                print('.',end='')
            else:
                print('v',end='')
        print('')
