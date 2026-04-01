from sys import stdin

n = int(stdin.readline())
l = list(map(int, stdin.readline().split()))
a, b = map(int, stdin.readline().split())
res = 0
for i in l:
    res += i // a + (1 if i % a else 0)
print(res)
print(n // b, n % b)