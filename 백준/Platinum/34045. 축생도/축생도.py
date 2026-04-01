from sys import stdin

n = int(stdin.readline())

l1 = list(map(int, stdin.readline().split()))
l2 = list(map(int, stdin.readline().split()))
l1.insert(0, 0)
l2.insert(0, 0)
ll1 = l1.copy()
ll1.sort()
ll2 = l2.copy()
ll2.sort()

n += 1

c = 0
for i in range(n):
    if ll1[i] != ll2[i]:
        print("NO")
        c = 1
        break

if not c:
    for i in range(n):
        if c:
            break
        if l2[i] == i or l1[i] == l2[i]:
            continue
        v = [0] * (n + 1)
        t = l2[i]

        temp = 0
        idx = i
        while not v[idx]:
            v[idx] = 1
            if l1[idx] == l2[i]:
                temp = 1
                break
            idx = l1[idx]
        if not temp:
            c = 1

    if c:
        print("NO")
    else:
        print("YES")
