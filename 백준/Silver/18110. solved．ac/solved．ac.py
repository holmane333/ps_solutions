from sys import stdin
from math import floor
n = int(stdin.readline())
if (n):
    l = [int(stdin.readline()) for i in range(n)]
    l.sort()
    t = int(floor(n * 15 / 100 + 0.5))
    print(floor((sum(l[t:len(l)-t])) / (len(l) - t * 2) + 0.5))
else: print(0)