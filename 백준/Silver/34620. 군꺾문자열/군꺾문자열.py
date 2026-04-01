import sys;input=lambda:sys.stdin.readline().rstrip()

a, b = map(int, input().split())
if (b.bit_count() != 1): print(-1)
else:
    res = []
    t = (1 << (b.bit_length() - 1))
    while (a or t):
        while (a >= t):
            a -= t
            res.append('G')
        t >>= 1
        if (t != 0): res.append('K')
    print(''.join(res[::-1]))