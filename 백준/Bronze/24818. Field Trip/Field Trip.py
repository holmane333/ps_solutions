from sys import stdin

n = int(stdin.readline())
l = list(map(int, stdin.readline().split()))
s = sum(l)
if (s % 3): print(-1)
else:
    s //= 3
    a = []
    t = 0
    c = 0
    for i in range(len(l)):
        t += l[i]
        if (t > s):
            print(-1)
            c = 1
            break
        if (t == s):
            t = 0
            a.append(i + 1)
    
    if (not c):
        print(a[0], a[1])