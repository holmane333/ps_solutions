from sys import stdin

tmp = [0 for i in range(100100)]
prime = []

for i in range(2, 100010):
    if (not tmp[i]):
        prime.append(i)
        for j in range(i * i, 100010, i):
            tmp[j] = 1

res = []
for _ in range(int(stdin.readline())):
    N = int(stdin.readline())
    l = sorted(list(map(int, stdin.readline().split())))
    best = float('inf')
    for i in range(len(prime) - N):
        tmp = 0
        for j in range(N):
            tmp += abs(l[j] - prime[i + j])
        best = min(best, tmp)
    res.append(str(best))
print('\n'.join(res))