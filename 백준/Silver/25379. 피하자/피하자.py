from sys import stdin

n = int(stdin.readline())
s = list(map(int, stdin.readline().split()))

r1 = 0
r2 = 0
cnt = 0

for i in range(n):
	if (s[i] % 2):
		r1 += i - cnt
		r2 += n - 1 - i - cnt
		cnt += 1

print(min(r1, r2))