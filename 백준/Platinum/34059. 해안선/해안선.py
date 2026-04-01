from sys import stdin

n = int(stdin.readline())
a, b = map(int, stdin.readline().split())
if (a > b):
    a, b = b, a
 
MOD = 1000000007

factorial = [0] * 1000001
ex = [0] * 1000001

for i in range(0, 1000001):
    if (i): ex[i] = (ex[i - 1] * 2) % MOD
    else: ex[i] = 1

for i in range(0, 1000001):
    if (i): factorial[i] = (i * factorial[i - 1]) % MOD
    else: factorial[i] = 1

def mod(n, k):
    if (k == 1): return n
    t = mod(n, k // 2)
    result = (t * t) % MOD
    if (k % 2 == 1): result = (result * n) % MOD
    return result

def f(n, m):
    n1 = mod((factorial[n] * factorial[m]) % MOD, MOD - 2)
    n2 = ((factorial[n + m] * n1) % MOD)
    return n2

if (b - a == 1):
    res = 0
    t1 = n - b
    t2 = a - 2
    res = (f(t1, t2)) % MOD
    res = (res + ex[n - 3]) % MOD
    print(res)
else:
    t1 = n - b
    t2 = a - 2
    print((f(t1, t2) * (ex[b - a - 1]))% MOD)
