from sys import stdin

n, m = map(int, stdin.readline().split())

for i in range(m):
    l = list(map(int, stdin.readline().split()))
    l2 = []
    l3 = False
    ans = 1
    c = 0
    for j in l:
        if j > 0:
            ans *= j
            c = 1
        elif j < 0:
            l2.append(j)
        else:
            l3 = True
    l2.sort()
    for j in range(0, len(l2) - 1, 2):
        ans *= l2[j] * l2[j + 1]
        c = 1
    if ans == 1 and c == 0:
        if l3:
            ans = 0
        else:
            ans = l[0]
    print(ans)
