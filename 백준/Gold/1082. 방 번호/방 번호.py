from sys import stdin
n = int(stdin.readline())
l = list(map(int, stdin.readline().split()))
m = int(stdin.readline())
dp = [0 for i in range(60)]
for i in range(n - 1, -1, -1):
	for j in range(l[i], m + 1):
		dp[j] = max(dp[j], dp[j - l[i]] * 10 + i)
print(dp[m])