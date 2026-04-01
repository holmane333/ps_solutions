from sys import stdin
import random

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 61, 73]


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def miller_rabin(n, a):
    if a % n == 0:
        return False
    k = n - 1

    while True:
        d = pow(a, k, n)
        if k % 2:
            return d == 1 or d == n - 1
        if d == n - 1:
            return True
        k >>= 1


def miller_rabin_primality_testing(n):
    if n == 1:
        return False

    for i in range(len(primes)):
        if n == primes[i]:
            return True
        if n % primes[i] == 0:
            return False
        if not miller_rabin(n, primes[i]):
            return False
    return True


def pollard_rho(n, res):
    if n == 1:
        return

    if not n % 2:
        res.append(2)
        pollard_rho(n // 2, res)
        return

    if miller_rabin_primality_testing(n):
        res.append(n)
        return

    x = random.randint(2, n - 1)
    y = x
    c = random.randint(1, 20)
    g = 1
    while g == 1:
        x = (x * x + c) % n
        y = (y * y + c) % n
        y = (y * y + c) % n
        g = gcd(abs(x - y), n)
        if g == n:
            x = random.randint(2, n - 1)
            y = x
            c = random.randint(1, 20)

    pollard_rho(g, res)
    pollard_rho(n // g, res)


n = int(stdin.readline())
if n == 1:
    print(1)
else:
    res = []
    pollard_rho(n, res)
    res.sort()

    ans = n // res[0] * (res[0] - 1)
    for i in range(1, len(res)):
        if res[i - 1] != res[i]:
            ans = ans // res[i] * (res[i] - 1)

    print(ans)
