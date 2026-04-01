import sys;input=lambda:sys.stdin.readline().rstrip()

sieve = [1 for i in range(10100)]
sieve[0] = sieve[1] = 0

for i in range(2, 10100):
    if (sieve[i]):
        for j in range(i * i, 10100, i):
            sieve[j] = 0

res = []
for _ in range(int(input())):
    N = int(input())
    if (not sieve[N + 1]): res.append('0')
    else: res.extend(['1', f'{1} {N + 1}'])
print('\n'.join(res))