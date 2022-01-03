from sys import stdin
a,b=map(int,stdin.readline().split())
if a>b:
    print('>')
elif a<b:
    print('<')
else:
    print('==')
