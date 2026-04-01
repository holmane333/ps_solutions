from sys import stdin

while (True):
	k = int(stdin.readline())
	if (not k):
		break
	left = 1
	right = int(1e15)
	res = right
	pos = 0
	while (left <= right):
		mid = (left + right) // 2
		#print(mid)
		cnt = (mid // 4) * 7 + (mid % 4) * 2
		t = 10
		while (mid >= t):
			cnt += mid - t + 1
			t *= 10
		#print(mid, cnt, t, k)
		if (cnt < k):
			left = mid + 1
		else:
			if (res > mid):
				res = mid
				pos = cnt - k
				#print(res, pos)
			right = mid - 1
	
	#print(res, pos)
	if (k <= 2):
		if (k == 1):
			print(1)
		else:
			print(2)
	else:
		if (res % 4 == 2):
			res = res * 10 + 0
		elif (res % 4 == 1 or res % 4 == 3):
			res = res * 10 + 2
		res = (str(res))[::-1]
		print(res[pos])