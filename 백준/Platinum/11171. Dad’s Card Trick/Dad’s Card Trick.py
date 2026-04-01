import sys;input=lambda:sys.stdin.readline().rstrip()
res = []
for _ in range(int(input())):
    N, K = map(int, input().split())
    if (N == K): res.append(str((N // 2) + (N % 2)))
    else: res.append(str(min(2 * K, N)))
print('\n'.join(res))