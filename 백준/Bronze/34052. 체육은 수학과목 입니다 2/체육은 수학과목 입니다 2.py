from sys import stdin

res = 0
for i in range(4):
    n = int(stdin.readline())
    res += n
res += 300
if (res <= 1800):
    print("Yes")
else:
    print("No")