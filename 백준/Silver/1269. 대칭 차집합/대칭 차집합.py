from sys import stdin

n, m = map(int, stdin.readline().split())
a = set(map(int, stdin.readline().split()))
b = set(map(int, stdin.readline().split()))
print(len(a - b) + len(b - a))