import sys;input=lambda:sys.stdin.readline().rstrip()

s = input()
c = 1
for i in range(len(s)):
    if (s[i] != s[len(s) - 1 - i]):
        c = 0
        break
print(c)