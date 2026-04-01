import sys;input=lambda:sys.stdin.readline().rstrip()
import heapq

C, N = map(int, input().split())
l1 = [int(input()) for i in range(C)]
l2 = [list(map(int, input().split())) for i in range(N)]
l1.sort()
l2.sort()

pq = []
res = 0
idx = 0
for i in l1:
    while (idx < len(l2) and l2[idx][0] <= i):
        heapq.heappush(pq, l2[idx][1])
        idx += 1
    while (pq):
        if (pq[0] < i): heapq.heappop(pq)
        else:
            heapq.heappop(pq)
            res += 1
            break
print(res)