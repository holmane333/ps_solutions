from sys import stdin
import heapq

testcase = int(stdin.readline().rstrip())
for tc in range(testcase):
	minheap = []
	maxheap = []
	n = int(stdin.readline().rstrip())
	visit = [0 for i in range(n + 1)]
	for i in range(n):
		a, k = map(str, stdin.readline().rstrip().split())
		k = int(k)
		if (a == 'I'):
			heapq.heappush(maxheap, (-k, i))
			heapq.heappush(minheap, (k, i))
		else:
			if (k == -1):
				if (len(minheap) != 0):
					if (visit[minheap[0][1]] == 0):
						visit[minheap[0][1]] = 1
						heapq.heappop(minheap)
			else:
				if (len(maxheap) != 0):
					if (visit[maxheap[0][1]] == 0):
						visit[maxheap[0][1]] = 1
						heapq.heappop(maxheap)
			while (len(minheap) != 0):
				if (visit[minheap[0][1]] == 0):
					break
				heapq.heappop(minheap)
			while (len(maxheap) != 0):
				if (visit[maxheap[0][1]] == 0):
					break
				heapq.heappop(maxheap)
	if (len(minheap) == 0 or len(maxheap) == 0):
		print("EMPTY")
	else:
		Max = heapq.heappop(maxheap)[0] * -1
		Min = heapq.heappop(minheap)[0]
		print(str(Max) + " " + str(Min))