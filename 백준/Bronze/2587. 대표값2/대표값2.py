import sys;input=lambda:sys.stdin.readline().rstrip()

l = [int(input()) for i in range(5)]
l.sort()
print(sum(l) // len(l), l[len(l) // 2], sep='\n')
