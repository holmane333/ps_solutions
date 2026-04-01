from sys import stdin

n = int(stdin.readline())

sq_prime = []
v = [1 for i in range(50000)]
v[0] = v[1] = 0
for i in range(4, 50000, 2): v[i] = 0
for i in range(3, 50000, 2):
    if (v[i]):
        for j in range(i * i, 50000, i): v[j] = 0
for i in range(50000):
    if (v[i]): sq_prime.append(i * i)

l = n
r = n * 2
cnt = len(sq_prime)

def func(m):
    res = 0
    for a in range(cnt):
        res += m // (sq_prime[a])
        for b in range(a + 1, cnt):
            if (sq_prime[a] * sq_prime[b] > m): break
            res -= m // (sq_prime[a] * sq_prime[b])
            for c in range(b + 1, cnt):
                if (sq_prime[a] * sq_prime[b] * sq_prime[c] > m): break
                res += m // (sq_prime[a] * sq_prime[b] * sq_prime[c])
                for d in range(c + 1, cnt):
                    if (sq_prime[a] * sq_prime[b] * sq_prime[c] * sq_prime[d] > m): break
                    res -= m // (sq_prime[a] * sq_prime[b] * sq_prime[c] * sq_prime[d])
                    for e in range(d + 1, cnt):
                        if (sq_prime[a] * sq_prime[b] * sq_prime[c] * sq_prime[d] * sq_prime[e] > m): break
                        res += m // (sq_prime[a] * sq_prime[b] * sq_prime[c] * sq_prime[d] * sq_prime[e])
                        for f in range(e + 1, cnt):
                            if (sq_prime[a] * sq_prime[b] * sq_prime[c] * sq_prime[d] * sq_prime[e] * sq_prime[f] > m): break
                            res -= m // (sq_prime[a] * sq_prime[b] * sq_prime[c] * sq_prime[d] * sq_prime[e] * sq_prime[f])
    return res

while (l <= r):
    m = (l + r) // 2
    
    res = m - func(m)
    
    if (res < n): l = m + 1
    elif (res > n): r = m - 1
    else:
        while(m - 1 - func(m - 1) == n): m -= 1
        print(m)
        break
