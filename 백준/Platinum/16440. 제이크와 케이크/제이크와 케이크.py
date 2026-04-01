from sys import stdin

n = int(stdin.readline())
s = stdin.readline().rstrip()

mid = n // 2
cnt = 0
for i in range(mid):
    if (s[i] == 's'): cnt += 1
    else: cnt -= 1

if (not cnt): print(1, mid, sep='\n')
else:
    idx = 0
    for i in range(mid, n):
        if (s[i] == 's'): cnt += 1
        else: cnt -= 1
        if (s[i - mid] == 's'): cnt -= 1
        else: cnt += 1
        if (not cnt):
            idx = i
            break
    print(2)
    print(idx - mid + 1, idx + 1)