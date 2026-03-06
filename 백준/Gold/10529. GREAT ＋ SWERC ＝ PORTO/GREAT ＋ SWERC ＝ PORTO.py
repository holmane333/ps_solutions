from sys import stdin

n = int(stdin.readline())
l = []
a = dict()
aa = [0 for _ in range(11)]
res = 0
for i in range(n):
    l.append(stdin.readline().rstrip())

def func(i, j):
    global res
    if (i == n):
        t = 0
        s = []
        for k in range(n):
            for idx in range(len(l[k])):
                t *= 10
                t += a[l[k][idx]]
            s.append(t)
            t = 0
        if (sum(s[:-1]) == s[-1]): res += 1
        return
    idx = l[i][j]
    if (idx in a):
        if (j == len(l[i]) - 1): func(i + 1, 0)
        else: func(i, j + 1)
        return
    for k in range(10):
        if (not j and not k): continue
        idx = l[i][j]
        if (aa[k]): continue
        a[idx] = k
        aa[k] = 1
        if (j == len(l[i]) - 1): func(i + 1, 0)
        else: func(i, j + 1)
        aa[k] = 0
        a.pop(idx)

func(0, 0)
print(res)