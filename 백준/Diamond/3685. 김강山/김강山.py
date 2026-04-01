# slope trick
from sys import stdin
import heapq

for _ in range(int(stdin.readline())):
    n, k = map(int, stdin.readline().split())
    l = list(map(int, stdin.readline().split()))
    if (abs(l[0] - l[-1]) > k * (n - 1)):
        print('impossible')
        continue
    q1, q2 = [-l[0] for i in range(100)], [l[0] for i in range(100)]
    res = 0
    for idx, i in enumerate(l[1:-1]):
        tmp = (idx + 1) * k
        left = -q1[0] - tmp
        right = q2[0] + tmp
        
        if (left <= i <= right):
            heapq.heappush(q1, -(i + tmp))
            heapq.heappush(q2, i - tmp)
        elif (i < left):
            res += left - i
            heapq.heappop(q1)
            heapq.heappush(q1, -(i + tmp))
            heapq.heappush(q1, -(i + tmp))
            heapq.heappush(q2, left - tmp)
        elif (i > right):
            res += i - right
            heapq.heappop(q2)
            heapq.heappush(q2, i - tmp)
            heapq.heappush(q2, i - tmp)
            heapq.heappush(q1, -(right + tmp))
    # 마지막 값 강제 맞추기
    tmp = (n - 1) * k
    last_val = l[-1]
    while (1):
        left = -q1[0] - tmp
        right = q2[0] + tmp
        if (last_val < left):
            res += left - last_val
            heapq.heappop(q1)
            heapq.heappush(q1, -(last_val + tmp))
            heapq.heappush(q1, -(last_val + tmp))
            heapq.heappush(q2, left - tmp)
        elif (last_val > right):
            res += last_val - right
            heapq.heappop(q2)
            heapq.heappush(q2, last_val - tmp)
            heapq.heappush(q2, last_val - tmp)
            heapq.heappush(q1, -(right + tmp))
        else:
            break
    
    print(res)