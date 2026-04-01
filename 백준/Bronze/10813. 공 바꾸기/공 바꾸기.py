import sys;input=lambda:sys.stdin.readline().rstrip()

N, M = map(int, input().split())
l = [i for i in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    l[a], l[b] = l[b], l[a]
print(*l[1:])