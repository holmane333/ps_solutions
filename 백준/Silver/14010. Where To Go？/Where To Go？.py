from sys import stdin
n = int(stdin.readline())
s = stdin.readline().rstrip()
res = []

for i in range(n):
	t = stdin.readline().rstrip()
	cc = 0
	for j in range(len(s) - len(t) + 1):
		l1, l2 = [-1 for xx in range(27)], [-1 for yy in range(27)]
		c = 0
		for k in range(len(t)):
			if not ((l1[ord(t[k]) - ord('a')] == -1 and l2[ord(s[j + k]) - ord('A')] == -1) or (l1[ord(t[k]) - ord('a')] != -1 and l2[ord(s[j + k]) - ord('A')] != -1)):
				c = 1
				break
			if (l1[ord(t[k]) - ord('a')] != -1 and l1[ord(t[k]) - ord('a')] != ord(s[j + k]) - ord('A')):
				c = 1
				break
			if (l2[ord(s[j + k]) - ord('A')] != -1 and l2[ord(s[j + k]) - ord('A')] != ord(t[k]) - ord('a')):
				c = 1
				break
			l1[ord(t[k]) - ord('a')] = ord(s[j + k]) - ord('A')
			l2[ord(s[j + k]) - ord('A')] = ord(t[k]) - ord('a')
		if (c == 0):
			res.append(str(j))
			cc = 1
			break
	if (cc == 0):
		res.append('-')

print('\n'.join(res))