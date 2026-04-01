from sys import stdin
n = int(stdin.readline())
for i in range(n):
	s = list(map(str, stdin.readline().rstrip().split()))
	for j in range(len(s)):
		s[j] = s[j][::-1]
	print(*s)