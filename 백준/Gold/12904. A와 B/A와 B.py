import sys;input=lambda:sys.stdin.readline().rstrip()

S, T = input(), input()

d = 1
left, right = 0, len(T) - 1
while (len(S) < right - left + 1):
    if (d):
        if (T[right] == 'B'): d = not d
        right -= 1
    else:
        if (T[left] == 'B'): d = not d
        left += 1
print(1 if T[left:right + 1][::1 if d else -1] == S else 0)