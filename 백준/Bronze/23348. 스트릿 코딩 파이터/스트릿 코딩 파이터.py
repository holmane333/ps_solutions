from sys import stdin

a, b, c = map(int, stdin.readline().split())
n = int(stdin.readline())

m = 0
for i in range(n):
	d, e, f = 0, 0, 0
	for j in range(3):
		d1, e1, f1 = map(int, stdin.readline().split())
		d += d1
		e += e1
		f += f1
	m = max(m, d * a + e * b + f * c)
print(m)