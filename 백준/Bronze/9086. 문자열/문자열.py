import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
for _ in range(N):
    s = input()
    print(s[0] + s[-1])