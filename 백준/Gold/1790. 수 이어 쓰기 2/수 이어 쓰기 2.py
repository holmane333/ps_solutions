import sys;input=lambda:sys.stdin.readline().rstrip()

N, K = map(int, input().split())

cnt = 9
dig = 1
while (K > cnt * dig):
    K -= cnt * dig
    cnt *= 10
    dig += 1

num = (10 ** (dig - 1)) + (K - 1) // dig
pos = (K - 1) % dig

if (N < num):
    print(-1)
else:
    l = []
    while (num):
        l.append(num % 10)
        num //= 10
    l.reverse()
    print(l[pos])