from sys import stdin
from collections import deque

a = stdin.readline().rstrip()
t = deque(str(stdin.readline().rstrip()))

lq = deque()
rq = deque()

k = len(a)
res = 0
n = int(stdin.readline())
b = 0
for i in range(n):
    s = str(stdin.readline().rstrip())
    if (b): continue
    if (not t and (not lq or not rq)):
        b = 1
        continue
    if (s[0] == 'L'):
        c = 0
        while (t):
            lq.append(t.popleft())
            if (len(lq) >= k and lq[-1] == a[-1]):
                c = 1
                for i in range(k):
                    if (lq[len(lq) - k + i] != a[i]):
                        c = 0
                        break
            if (c == 1):
                for i in range(k):
                    lq.pop()
                break
        if (not c):
            while (len(rq)):
                lq.append(rq.popleft())
                if (len(lq) >= k and lq[-1] == a[-1]):
                    c = 1
                    for i in range(k):
                        if (lq[len(lq) - k + i] != a[i]):
                            c = 0
                            break
                if (c == 1):
                    for i in range(k):
                        lq.pop()
                    break
        res += c
    else:
        c = 0
        while (t):
            rq.appendleft(t.pop())
            if (len(rq) >= k and rq[0] == a[0]):
                c = 1
                for i in range(k):
                    if (rq[i] != a[i]):
                        c = 0
                        break
            if (c == 1):
                for i in range(k):
                    rq.popleft()
                break
        if (not c):
            while (len(lq)):
                rq.appendleft(lq.pop())
                if (len(rq) >= k and rq[0] == a[0]):
                    c = 1
                    for i in range(k):
                        if (rq[i] != a[i]):
                            c = 0
                            break
                if (c == 1):
                    for i in range(k):
                        rq.popleft()
                    break
        res += c
            

s = ''.join(lq) + ''.join(t) + ''.join(rq)

print(res)
print(s)
if (s.find(a) == -1): print('Perfect!')
else: print('You Lose!')
