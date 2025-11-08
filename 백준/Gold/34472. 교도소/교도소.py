import sys;input=lambda:sys.stdin.readline().rstrip()
N = int(input())
l = list(map(int, input().split()))
C = sum(l) // N

res = 0
left = 0
for _ in range(2):
    for i in range(N):
        if (l[i] + left > C):
            l[i], left = C, l[i] + left - C
            res += left
        else: l[i], left = l[i] + left, 0
print(res)