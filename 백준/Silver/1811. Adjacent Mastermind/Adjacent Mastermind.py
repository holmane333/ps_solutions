from sys import stdin

while (True):
    t = stdin.readline()
    if (t[0] == '#'): break
    a, b = map(str, t.split())
    
    black, grey, white = 0, 0, 0
    idx = [0 for i in range(len(a))]
    alp = [0 for i in range(130)]
    for i in range(len(a)):
        if (a[i] == b[i]):
            black += 1
            idx[i] = 1
    for i in range(len(a)):
        if (a[i] == b[i]): continue
        if (i and a[i - 1] == b[i] and not idx[i - 1]):
            grey += 1
            idx[i - 1] = 1
        elif (i < len(a) - 1 and a[i + 1] == b[i] and not idx[i + 1]):
            grey += 1
            idx[i + 1] = 1
        else:
            alp[ord(b[i])] += 1
    for i in range(len(a)):
        if (not idx[i] and alp[ord(a[i])]):
            alp[ord(a[i])] -= 1
            white += 1
    print(f"{b}: {black} black, {grey} grey, {white} white")