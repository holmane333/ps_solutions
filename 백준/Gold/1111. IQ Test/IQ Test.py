import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
l = list(map(int, input().split()))

if (N == 1): print('A')
elif (N == 2):
    if (l[0] == l[1]): print(l[0])
    else: print('A')
else:
    a = 0
    if (l[1] - l[0] != 0): a = (l[2] - l[1]) // (l[1] - l[0])
    b = l[1] - l[0] * a
    c = 1
    for i in range(1, N - 1):
        if (l[i + 1] != l[i] * a + b):
            c = 0
            print('B')
            break
    if (c):
        print(l[-1] * a + b)