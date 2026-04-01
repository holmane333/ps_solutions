import sys;input=lambda:sys.stdin.readline().rstrip()
from itertools import permutations

N = int(input())
res = 0
l1 = []
l2 = []
for i in range(N):
    l1.append(str(input()))
for i in range(N):
    l2.append(str(input()))

def func(a: str, b: str) -> int:
    tmp = 0
    for i in range(len(a)):
        tmp += (1 if a[i] != b[i] else 0)
    return tmp

for per in permutations([j for j in range(N)]):
    tmp = 0
    for i in range(len(l1)):
        tmp += func(l1[i], l2[per[i]])
    res = max(res, tmp)
print(res)