from sys import stdin

n = int(stdin.readline())
d = dict({'Baba': set()})
for i in range(n):
    a, _, b = map(str, stdin.readline().split())
    if (a not in d):
        d[a] = set()
    d[a].add(b)

res = set()
l = ['Baba']
while (l):
    t = l.pop()
    if (t not in d):
        continue
    t = d[t]
    for i in t:
        if (i not in res):
            res.add(i)
            l.append(i)

print('\n'.join(sorted(list(res))))