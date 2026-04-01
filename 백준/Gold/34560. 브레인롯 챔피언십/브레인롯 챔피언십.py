import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
l = [list(map(str, input().split())) for i in range(N)]
l = [[i[0], int(i[1]), int(i[2]), int(i[3])] for i in l]
d = [[] for i in range(N)]

def func(a: list, b: list) -> int:
    r1, r2 = [0, 0], [0, 0]
    for i in range(1, len(a)):
        if (a[i] > b[i]):
            r1[0] += 1
            r2[1] += 1
        elif (a[i] < b[i]):
            r1[1] += 1
            r2[0] += 1
        else:
            r1[0] += 1
            r2[0] += 1
    if (r1[0] > r2[0]): return 1
    elif (r1[0] < r2[0]): return -1
    else: return 0
        
for i in range(N):
    for j in range(i + 1, N):
        r = func(l[i], l[j])
        if (r == 1):
            d[j].append(i)
        elif (r == -1):
            d[i].append(j)

res = []
for i in range(N):
    if (not d[i]): res.append(l[i][0])
res.sort()

q = []
v = [0 for i in range(N)]
c = 0
for i in range(N):
    if (c): break
    if (not v[i]):
        q.append((i, 0))
        
        while (q):
            if (c): break
            x, t = q.pop()
            if (t):
                v[x] = 2
                continue
            if (v[x] == 1):
                c = 1
                break
            elif (v[x] == 2): continue
            v[x] = 1
            q.append((x, 1))
            for j in d[x]:
                if (v[j] == 2): continue
                elif (v[j] == 1):
                    c = 1
                    break
                q.append((j, 0))

if (c): print('Paradoxe Absurdo')
else: print('\n'.join(res))