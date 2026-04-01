from sys import stdin
for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    if (n == 2):
        print('YES')
        print(1, 2)
        print(1, 2)
    elif (n == 4):
        print('YES')
        print(1, 2, 3, 4)
        print(1, 2, 4, 3)
    else:
        print('NO')