from sys import stdin

a = stdin.readline().rstrip()
b = stdin.readline().rstrip()
c = stdin.readline().rstrip()

print(int(a) + int(b) - int(c))
print(int(a + b) - int(c))