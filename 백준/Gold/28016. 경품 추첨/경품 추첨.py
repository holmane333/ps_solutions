from sys import stdin

n, m = map(int, stdin.readline().split())

a = [[0 for i in range(110)]]
dp = [[[0 for i in range(110)] for j in range(110)] for k in range(110)]
for i in range(1, n + 1):
	a.append([0] + list(map(int, stdin.readline().split())) + [0])
	for j in range(1, m + 1):
		if (a[i][j] == 2):
			dp[i][j][0] = 1

for i in range(1, n + 1):
	for j in range(1, m + 1):
		if (a[i][j] == 1):
			continue
		if (a[i - 1][j] != 1):
			for k in range(n + 1):
				dp[i][j][k] += dp[i - 1][j][k]
				if (k == 0):
					continue
				if (a[i][j - 1] == 1):
					dp[i][j][k] += dp[i - 1][j - 1][k - 1]
				if (a[i][j + 1] == 1):
					dp[i][j][k] += dp[i - 1][j + 1][k - 1]

maxp = 0
maxn = 0
for i in range(1, m + 1):
	nown = 0;
	for j in range(n + 1):
		nown = nown * 2 + dp[n][i][j]
	if (maxn < nown):
		maxn = nown
		maxp = i


print(maxp - 1)