import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
a, b = map(int, input().split())
if (N <= 2 or (N == 3 and (a == b == 2))): print(1)
else:
    if (N == 3):
        if (a == b == 2): print(1)
        else: print(4)
    else: print((N * N) // 2 + ((N % 2) & ((a + b + 1) % 2)))