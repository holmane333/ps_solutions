from sys import stdin

n = int(stdin.readline())
res = ["" for i in range(2 * n)]
res[1] = "*" * n + " " * (2 * n - 3) + "*" * n

for i in range(2, n):
	res[i] = " " * (i - 1) + "*" + " " * (n - 2) + "*" + " " * (2 * n - 3 - 2 * (i - 1)) + "*" + " " * (n - 2) + "*"
res[n] = " " * (n - 1) + "*" + " " * (n - 2) + "*" + " " * (n - 2) + "*";

for i in range(1, n):
	res[2 * n - i] = res[i]

del res[0]
print("\n".join(res))