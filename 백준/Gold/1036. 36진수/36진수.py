from sys import stdin

n = int(stdin.readline())
l = [[0, i] for i in range(50)]
res = 0
for i in range(n):
	a = stdin.readline().rstrip()
	res += int(a, 36)
	k2 = 1
	for j in a[::-1]:
		temp = 0
		if (j.isdigit()):
			temp = int(j)
		else:
			temp = int(j, 36)
		l[temp][0] += 35 * k2 - temp * k2;
		k2 *= 36
t = int(stdin.readline())
l.sort(key = lambda x : (-x[0], -x[1]))

for i in range(t):
	res += l[i][0]

res2 = ""
while (res):
	temp = res % 36
	if (temp >= 10):
		temp = chr(55 + temp)
	else:
		temp = str(temp)
	res2 += temp
	res //= 36
if (res2 == ""):
	res2 = "0"
print(res2[::-1])