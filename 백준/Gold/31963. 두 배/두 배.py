import sys

n = int(sys.stdin.readline())
l = list(map(int, sys.stdin.readline().split()))

cnt = [0 for i in range(n + 1)]
cnt2 = [0 for i in range(n + 1)]

for i in range(1, n):
    if (l[i] < l[i - 1]):
        temp = l[i]
        while (temp < l[i - 1]):
            temp <<= 1
            cnt[i] += 1
    else:
        temp = l[i - 1]
        while (l[i] >= temp):
            temp <<= 1
            if (l[i] < temp):
                break
            cnt[i] -= 1

res = 0
for i in range(1, n):
    cnt2[i] = max(0, cnt2[i - 1] + cnt[i])
    res += cnt2[i]

print(res)
        
