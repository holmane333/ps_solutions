from sys import stdin

def pown(a, b):
    res = 1;
    while (b):
        if (b & 1):
            res = res * a % 1000000007
        b >>= 1
        a = a * a % 1000000007
    return res

n = int(stdin.readline())
l = list(map(int, stdin.readline().split()))
l.sort()

res = 0
for i in range(n):
    res += pown(2, i) * l[i]
    res %= 1000000007
    res -= pown(2, n - i - 1) * l[i]
    res %= 1000000007
print(res)
