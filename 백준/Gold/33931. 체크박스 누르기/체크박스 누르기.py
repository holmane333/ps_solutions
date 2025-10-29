import sys;input=lambda:sys.stdin.readline().rstrip()

N, M = map(int, input().split())
if ((M // N) % 2): print(N - M % N)
else: print(M % N)