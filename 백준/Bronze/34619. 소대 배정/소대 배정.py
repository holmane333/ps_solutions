import sys;input=lambda:sys.stdin.readline().rstrip()

a, b, n, k = map(int, input().split())
k = (k // n) + (1 if k % n else 0) - 1
print(k // b + 1, k % b + 1)