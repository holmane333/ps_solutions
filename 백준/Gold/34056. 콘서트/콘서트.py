from sys import stdin

n = int(stdin.readline())
l = list(map(int, stdin.readline().split()))
q = int(stdin.readline())
for i in range(q):
    t = list(map(int, stdin.readline().split()))
    if (t[0] == 1):
        a, b = t[1], t[2]
        temp = b
        for j in range(a - 1, -1, -1):
            if (not temp): break
            m = min(temp, l[j])
            l[j] += m
            temp -= m
        temp = b
        for j in range(a, n):
            if (not temp): break
            m = min(temp, l[j])
            l[j] += m
            temp -= m
    else:
        a = t[1]
        print(l[a - 1])
