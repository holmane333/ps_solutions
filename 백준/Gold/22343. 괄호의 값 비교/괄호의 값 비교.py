from sys import stdin
tc = int(stdin.readline())

while(tc):
	tc -= 1
	data1 = stdin.readline().rstrip()
	data2 = stdin.readline().rstrip()
	maxlen = max(len(data1), len(data2))
	res1, idx1 = [0 for i in range(maxlen // 2 + 1)], 0
	res2, idx2 = [0 for i in range(maxlen // 2 + 1)], 0
	for i in range(len(data1)): # ()모양의 위치 저장 -> ()모양의 위치의 x제곱 값이기 때문
		if (data1[i] == '('):
			idx1 += 1
		else:
			if (data1[i - 1] == '('):
				res1[idx1] += 1
			idx1 -= 1
	
	cache = 0
	for i in range(len(res1)): # 2 이상인 수들을 모두 위치를 올려줘서 1로 바꿈 (비교를 쉽게 하기 위함)
		res1[i] += cache
		cache = res1[i] // 2
		res1[i] %= 2
	
	for i in range(len(data2)):
		if (data2[i] == '('):
			idx2 += 1
		else:
			if (data2[i - 1] == '('):
				res2[idx2] += 1
			idx2 -= 1
	
	cache = 0
	for i in range(len(res2)):
		res2[i] += cache
		cache = res2[i] // 2
		res2[i] %= 2
	
	c = 0
	for i in range(len(res1) - 1, -1, -1):
		if (res1[i] != res2[i]):
			if (res1[i] > res2[i]):
				print(">")
			else:
				print("<")
			c = 1
			break
	if (c == 0):
		print("=")