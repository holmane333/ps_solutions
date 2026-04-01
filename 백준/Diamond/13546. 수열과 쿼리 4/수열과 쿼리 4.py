from sys import stdin
from math import sqrt
from collections import deque

n, k = map(int, stdin.readline().split())
l = [0] + list(map(int, stdin.readline().split()))
sqrtn = int(sqrt(n))
m = int(stdin.readline())
q = [list(map(int, stdin.readline().split())) + [i] for i in range(m)]
q.sort(key=lambda x:(x[0] // sqrtn, x[1]))

dq = [deque() for i in range(100010)]
sqrtq = 300
cnt_sqrt = [0 for i in range(100010//sqrtq + 10)]
cnt = [0 for i in range(100010)]

def dq_add(idx, dir):
    if (dq[l[idx]]):
        t = dq[l[idx]][-1] - dq[l[idx]][0]
        cnt[t] -= 1
        cnt_sqrt[t // sqrtq] -= 1
    if (dir): dq[l[idx]].append(idx)
    else: dq[l[idx]].appendleft(idx)
    t = dq[l[idx]][-1] - dq[l[idx]][0]
    cnt[t] += 1
    cnt_sqrt[t // sqrtq] += 1

def dq_pop(idx, dir):
    t = dq[l[idx]][-1] - dq[l[idx]][0]
    cnt[t] -= 1
    cnt_sqrt[t // sqrtq] -= 1
    if (dir): dq[l[idx]].pop()
    else: dq[l[idx]].popleft()
    if (dq[l[idx]]):
        t = dq[l[idx]][-1] - dq[l[idx]][0]
        cnt[t] += 1
        cnt_sqrt[t // sqrtq] += 1

def find_max():
    for i in range(len(cnt_sqrt) - 1, -1, -1):
        if (cnt_sqrt[i] != 0):
            for j in range(sqrtq - 1, -1, -1):
                if (cnt[i * sqrtq + j] > 0):
                    return i * sqrtq + j
    return 0

res = [0 for i in range(m)]
s, e = q[0][0], q[0][1]

for i in range(s, e + 1):
    dq_add(i, 1)
res[q[0][2]] = find_max()

for i in range(1, m):
    a, b = q[i][0], q[i][1]
    
    for j in range(s - 1, a - 1, -1): dq_add(j, 0)
    for j in range(e + 1, b + 1): dq_add(j, 1)
    for j in range(s, a): dq_pop(j, 0)
    for j in range(e, b, -1): dq_pop(j, 1)

    res[q[i][2]] = find_max()
    s, e = a, b

print('\n'.join(map(str, res)))

