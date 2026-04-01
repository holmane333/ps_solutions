# slope trick
from sys import stdin
import heapq

n, k = map(int, stdin.readline().split())
l = list(map(int, stdin.readline().split()))
q1, q2 = [-l[0]], [l[0]]
res = 0
for idx, i in enumerate(l[1:]):
    tmp = (idx + 1) * k
    left = -q1[0] - tmp
    right = q2[0] + tmp
    
    if (left <= i <= right):
        heapq.heappush(q1, -(i + tmp))
        heapq.heappush(q2, i - tmp)
    elif (i < left):
        res += left - i
        heapq.heappush(q1, -(i + tmp))
        heapq.heappush(q1, -(i + tmp))
        heapq.heappop(q1)
        heapq.heappush(q2, left - tmp)
    elif (i > right):
        res += i - right
        heapq.heappush(q2, i - tmp)
        heapq.heappush(q2, i - tmp)
        heapq.heappop(q2)
        heapq.heappush(q1, -(right + tmp))
print(res)