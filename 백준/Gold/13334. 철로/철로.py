from sys import stdin
import heapq

n = int(stdin.readline())
l = []
for i in range(n):
    a, b = map(int, stdin.readline().split())
    if (a > b):
        a, b = b, a
    l.append([a, b])
l.sort(key = lambda x : (x[1], x[0]))
k = int(stdin.readline())
h = []
maxcnt = 0
cnt = 0
for i in range(n):
    if (l[i][1] - l[i][0] > k):
        continue
    while (h and l[i][1] - h[0] > k):
        heapq.heappop(h)
        cnt -= 1
    heapq.heappush(h, l[i][0])
    cnt += 1
    if (maxcnt < cnt):
        maxcnt = cnt
print(maxcnt)
