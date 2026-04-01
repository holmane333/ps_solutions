from sys import stdin

n = int(stdin.readline())
d = dict()
s = set()
idx = {'left': 1, 'right': 2, 'any': 0}
for i in range(n):
    a, b, c = map(str, stdin.readline().split())
    c = int(c)
    s.add(a)
    if not a in d:
        d[a] = [0, 0, 0]
    d[a][idx[b]] = c

res = 0
cnt = 0
for j in s:
    i = d[j]
    if i[0] and i[1] or i[0] and i[2] or i[1] and i[2] or i[0] > 1:
        res = 1
    t = max(i[1], i[2])
    if not t:
        cnt += 1
    else:
        cnt += t

if res:
    print(cnt + 1)
else:
    print('impossible')