import sys
from collections import deque

n = int(sys.stdin.readline())
temp = list(map(int, sys.stdin.readline().split()))

l1 = []
l2 = []

for i in range(n):
    if (temp[i] > 0): l1.append(temp[i])
    else: l2.append(temp[i])

l1.sort(reverse=True)
l2.sort()

deq1 = deque()
deq2 = deque()


res = []

for i in range(len(l1)):
    if (i % 2): deq1.appendleft(l1[i])
    else: deq1.append(l1[i])

for i in range(len(l2)):
    if (i % 2): deq2.appendleft(l2[i])
    else: deq2.append(l2[i])

l1 = list(deq1)
l2 = list(deq2)

if (len(l1) and l1[0] < l1[-1]): l1.reverse()
if (len(l2) and l2[0] < l2[-1]): l2.reverse()

for i in range(len(l1)):
    print(l1[i], end=' ')
for i in range(len(l2)):
    print(l2[i], end=' ')
print()
