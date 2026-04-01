from sys import stdin

n = int(stdin.readline())
# 131329
# 2937
t1 = "131329"
t2 = "2937"

if n == 1:
    print(-1)
elif n == 2:
    print(t2)
elif n == 3:
    print(t1)
else:
    if n == 2:
        print
    ans = []
    if n % 2:
        for i in range(n // 2 - 1):
            ans.append(t2)
        ans.append(t1)
    else:
        for i in range(n // 2):
            ans.append(t2)
    print(''.join(ans))
