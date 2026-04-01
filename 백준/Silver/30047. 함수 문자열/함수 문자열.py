import sys;input=lambda:sys.stdin.readline().rstrip()

s = input()
l = []
res = 0
for i in s[::-1]:
    if (i == 'x'):
        l.append(0)
    elif (i == 'g'):
        if (not l):
            res = -1
            break
        l[-1] += 1
    elif (i == 'f'):
        if (len(l) < 2):
            res = -1
            break
        l.append(min(l.pop(), l.pop()))
if (res == -1 or len(l) != 1): print(-1)
else: print(l[0])
