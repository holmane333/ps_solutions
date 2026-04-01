from sys import stdin

n, m = map(int, stdin.readline().rstrip().split())
l = []
for i in range(n):
    a, b = map(int, stdin.readline().rstrip().split())
    if a <= b:
        continue
    l.append([b, a])

n = len(l)
l.sort()

if not n:
    print(m)
else:
    res = m
    start = l[0][0]
    end = l[0][1]
    for i in range(1, n):
        if end >= l[i][0]:
            if end < l[i][1]:
                end = l[i][1]
        else:
            res += (end - start) * 2
            start = l[i][0]
            end = l[i][1]

    res += (end - start) * 2

    print(res)
