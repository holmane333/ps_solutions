from sys import stdin

n, k = map(int, stdin.readline().split())
t = 1
res = 0
for i in range(k):
    a = int(stdin.readline())
    res += (n - a + 1) * (a - t + 1)
    t = a + 1
print(res)