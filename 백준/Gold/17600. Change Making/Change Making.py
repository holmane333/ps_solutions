from sys import stdin
from collections import deque

n = int(stdin.readline())
arr = list(map(int, stdin.readline().split()))

l = [-1 for i in range(10 ** 5 + 2)]
q = deque()

for i in arr:
    l[i] = 1
    q.append(i)

while (len(q)):
    t = q.popleft()
    
    for i in arr:
        if (t + i <= 10 ** 5 and l[t + i] == -1):
            l[t + i] = l[t] + 1
            q.append(t + i)

c = 0
for i in range(2, 10 ** 5 + 1):
    cnt = 0
    t = i
    for j in sorted(arr, reverse=True):
        cnt += t // j
        t %= j
    if (cnt != l[i]):
        print(i)
        c = 1
        break

if (not c):
    print(-1)
        
        
