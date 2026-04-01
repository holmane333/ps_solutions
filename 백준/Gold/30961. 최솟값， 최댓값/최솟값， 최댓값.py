from sys import stdin
n = int(stdin.readline())

res = 0
prev = 0
l = list(map(int, stdin.readline().split()))
l.sort()
for i in l:
    res ^= i * i
    res ^= prev * i
    prev = i
print(res)
