s = input()
a = s.find('011')
if (a == -1): a = 1e9
else:
	a += 2
	t = 0
	for i in range(1, a):
		t += s[i - 1] == s[i]
	a -= t

b = s.find('100')
if (b == -1): b = 1e9
else:
	b += 2
	t = 0
	for i in range(1, b):
		t += s[i - 1] == s[i]
	b -= t

res = min(a, b, len(s))
if (res == len(s)):
	for i in range(1, len(s)):
		res -= s[i - 1] == s[i]
print(res)