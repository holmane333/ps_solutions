from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10**8)

n, k = map(int, stdin.readline().split())
dp = [0 for i in range(n + 2)]
ll = list(map(int, stdin.readline().split()))
l = [0 for i in range(n + 2)]
w = [0 for i in range(n + 2)]
for i in ll:
	l[i] = 1

pos = -1
for i in range(n - 1, -1, -1):
	if (l[i]):
		continue
	pos = -1
	for j in range(1, k + 1):
		if (i + j >= n + 1):
			break
		if (l[i + j]):
			continue
		pos = max(pos, dp[i + j])
		if (not w[i + j]):
			w[i] = 1
			if (dp[i] == 0):
				dp[i] = dp[i + j] + 1
			else:
				dp[i] = min(dp[i], dp[i + j] + 1)
			#dp[i] = dp[i + j] + 1
	if (w[i] == 0):
		if (pos != -1):
			dp[i] = pos + 1
#print(l)
#print(dp)
#print(w)
#print(max(dp))
#print(m)
print(dp[0])