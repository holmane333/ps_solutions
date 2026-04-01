from sys import stdin
import heapq

n = int(stdin.readline())
sta = int(stdin.readline())
l = [-int(stdin.readline()) for i in range(n - 1)]

heapq.heapify(l)
cnt = 0
while (len(l) != 0 and sta <= -l[0]):
	a = heapq.heappop(l)
	heapq.heappush(l, a + 1)
	sta += 1
	cnt += 1

print(cnt)