import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
res = []
for i in range(N):
    if (i % 2): res.append((i // 2 + 1))
    else: res.append(N + 1 - (i // 2 + 1))
print(*res[::-1])
