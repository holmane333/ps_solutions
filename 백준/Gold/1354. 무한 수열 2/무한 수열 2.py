from sys import stdin

n, p, q, x, y = map(int, stdin.readline().split())
d = {}
d[0] = 1

def a(n, d, p, q, x, y):
	if (n <= 0):
		return d[0]
	if (n in d):
		return d[n]
	b = a(n // p - x, d, p, q, x, y) + a(n // q - y, d, p, q, x, y)
	d[n] = b
	return b

print(a(n, d, p, q, x, y))