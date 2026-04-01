from sys import stdin
s = stdin.readline().rstrip()
r = 0
idx = 0
for i in range(len(s)):
    if (s[i] == '*'): idx = i
    else: r += int(s[i]) * (3 if i % 2 else 1)
r = (10 - r % 10) % 10
while (r % (3 if idx % 2 else 1)): r += 10
r //= (3 if idx % 2 else 1)
print(r)