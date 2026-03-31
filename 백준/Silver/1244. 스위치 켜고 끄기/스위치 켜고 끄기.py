import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
l = list(map(int, input().split()))

Q = int(input())
for i in range(Q):
    a, b = map(int, input().split())
    if (a == 1):
        for idx in range(b - 1, N, b):
            l[idx] ^= 1
    else:
        l[b - 1] ^= 1
        for interval in range(1, N):
            if (b - 1 - interval < 0 or b - 1 + interval >= N): break
            if (l[b - 1 - interval] ^ l[b - 1 + interval]): break
            l[b - 1 - interval] ^= 1
            l[b - 1 + interval] ^= 1
for i in range(N // 20 + (1 if N % 20 else 0)):
    for j in range(i * 20, min(N, i * 20 + 20)):
        print(l[j], end=' ')
    print()
