from sys import stdin
from collections import deque
#from queue import Queue as que

n = int(stdin.readline())
res = []
for i in range(n):
    q = deque()
    a, b = map(int, stdin.readline().split())
    v = [0 for _ in range(10000)]
    q.append([a, ""])
    v[a] = 1
    x = [0, ""]
    while q:
        x = q.popleft()
        #print(x)

        t = x[0] * 2 % 10000
        if (t == b):
            x[1] = x[1] + 'D'
            break
        elif (not v[t]):
            v[t] = 1
            q.append([t, x[1] + 'D'])
        
        t = x[0]
        if (not t):
            t = 9999
        else:
            t -= 1
        if (t == b):
            x[1] = x[1] + 'S'
            break
        elif (not v[t]):
            v[t] = 1
            q.append([t, x[1] + 'S'])
        
        t = x[0] % 1000 * 10 + x[0] // 1000
        if (t == b):
            x[1] = x[1] + 'L'
            break
        elif (not v[t]):
            v[t] = 1
            q.append([t, x[1] + 'L'])
        
        t = x[0]
        t = x[0] % 10 * 1000 + x[0] // 10
        if (t == b):
            x[1] = x[1] + 'R'
            break
        elif (not v[t]):
            v[t] = 1
            q.append([t, x[1] + 'R'])
    #print(x[1])
    res.append(x[1])
print('\n'.join(res))
