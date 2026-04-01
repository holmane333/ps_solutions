from sys import stdin

n = int(stdin.readline())
l = list(map(int, stdin.readline().split()))

t1, t2 = 0, 0
l2 = [(l[i], i) for i in range(n)]
l2.sort()
t1 = l2[0][0]
t2 = l2[1][0]
c = 0
if (n == 3):
    print(max(l2[0][0], l2[1][0]) - 1)
else:
    if (l2[0][0] < l2[1][0] and (l2[1][0] == l2[2][0] and l2[2][0] != l2[3][0])):
        if ((((l2[0][1] + 1) % n == l2[1][1]) and ((l2[0][1] - 1) % n == l2[2][1])) or (((l2[0][1] - 1) % n == l2[1][1]) and ((l2[0][1] + 1) % n == l2[2][1]))):
            c = 1
    if (l2[0][0] == l2[1][0] and l2[1][0] < l2[2][0]):
        if ((l2[0][1] + 1) % n == l2[1][1] or (l2[0][1] - 1) % n == l2[1][1]):
            c = 1
    if (not c):
        t1 -= 1
        t2 -= 1
    t1 -= 1
    t2 -= 1

    cnt = n - 2 - (1 if c else 2)
    mv = min(t2 - t1, cnt)
    cnt -= mv
    t2 -= mv + cnt // 2

    print(t2)