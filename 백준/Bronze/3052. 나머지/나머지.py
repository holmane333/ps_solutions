from sys import stdin
l=set()
for i in range(10):
    l.add(int(stdin.readline())%42)
print(len(l))