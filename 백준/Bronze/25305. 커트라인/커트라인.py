import sys;input=lambda:sys.stdin.readline().rstrip()

N, M = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
print(l[len(l) - M])
