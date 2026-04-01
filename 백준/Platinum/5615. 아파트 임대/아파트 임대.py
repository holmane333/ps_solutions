from sys import stdin

primes = [2, 7, 61]


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


n = int(stdin.readline().rstrip())
cnt = 0
for i in range(n):
    if miller_rabin_primality_testing(int(stdin.readline().rstrip()) * 2 + 1):
        cnt += 1

print(cnt)
