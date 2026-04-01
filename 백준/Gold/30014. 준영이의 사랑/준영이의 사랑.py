import sys

n = int(sys.stdin.readline())
l = list(map(int, sys.stdin.readline().split()))

l.sort(reverse=True)

res = [0 for i in range(n)]

for i in range(n):
    if (i % 2): res[n - 1 - i // 2] = l[i]
    else: res[i // 2] = l[i]

cnt = 0
for i in range(n):
    cnt += res[i] * res[i - 1]

print(cnt)
for i in res:
    print(i, end=' ')
print()
