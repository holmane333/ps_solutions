import sys;input=lambda:sys.stdin.readline().rstrip()

res = [(1 << 30), (1 << 30) + 1]
for _ in range(int(input())):
    a = int(input())
    if (a):
        print(2)
        print(*res)
    else:
        print('\n'.join(['1', '2']))