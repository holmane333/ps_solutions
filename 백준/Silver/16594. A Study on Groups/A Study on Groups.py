from sys import stdin

n, m = map(int, stdin.readline().split())
l = list(map(int, stdin.readline().split()))

l.sort()
t = n % m
tt = n // m

res = 0
i = 0
while (i < n):
    res += l[i]
    i += tt
    if (t > 0):
        i += 1
        t -= 1

print(sum(l[:m]), res)