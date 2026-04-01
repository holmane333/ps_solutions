import sys;input=lambda:sys.stdin.readline().rstrip()

n = int(input())
nums = [int(input()) for i in range(n)]

dp1 = [1] * (n + 1)
dp2 = [1] * (n + 1)
data = [-1] + nums

for i in range(n, 0, -1):
    dp1[i] = 1
    for j in range(n, i, -1):
        if data[i] < data[j]:
            dp1[i] = max(dp1[i], dp1[j] + 1)

for i in range(n, 0, -1):
    dp2[i] = 1
    for j in range(n, i, -1):
        if data[i] > data[j]:
            dp2[i] = max(dp2[i], dp2[j] + 1)

max_len = 0
for i in range(1, n + 1): max_len = max(max_len, dp1[i] + dp2[i] - 1)
print(max_len)