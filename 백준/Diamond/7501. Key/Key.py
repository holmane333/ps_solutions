from sys import stdin

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 61, 73]


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


a, b = map(int, stdin.readline().split())
res = []
for i in range(a, b + 1):
    if miller_rabin_primality_testing(i) or i == 9:
        res.append(i)

print(*res)
