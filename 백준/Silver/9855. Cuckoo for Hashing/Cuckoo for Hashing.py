from sys import stdin


tc = 0
while (1):
    tc += 1
    n1, n2, m = map(int, stdin.readline().split())
    if (n1 == n2 == m == 0):
        break
    l = []
    while (len(l) != m):
        l.extend(list(map(int, stdin.readline().split())))
    d1, d2 = dict(), dict()
    for i in l:
        t = i
        while (1):
            if (t % n1 not in d1):
                d1[t % n1] = t
                break
            else:
                t, d1[t % n1] = d1[t % n1], t
            
            if (t % n2 not in d2):
                d2[t % n2] = t
                break
            else:
                t, d2[t % n2] = d2[t % n2], t
    
    print(f"Case {tc}:")
    if (len(d1)):
        print("Table 1")
        for i in sorted(d1.items()):
            print(f"{i[0]}:{i[1]}")
    if (len(d2)):
        print("Table 2")
        for i in sorted(d2.items()):
            print(f"{i[0]}:{i[1]}")
