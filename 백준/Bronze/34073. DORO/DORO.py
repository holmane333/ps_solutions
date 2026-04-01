from sys import stdin

n = int(stdin.readline())
l = list(map(str, stdin.readline().split()))
l = [i + "DORO" for i in l]

print(' '.join(l))