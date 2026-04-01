from sys import stdin\

n, m = map(int, stdin.readline().split())
l = list(map(int, stdin.readline().split()))
l_r = [0]
sum = 0
for i in range(0, n):
    sum+=l[i]
    l_r.append(sum)

for _ in range(m):
    sum = 0
    a, b = map(int, stdin.readline().split())
    if a > b:
        a, b = b, a
    print(l_r[b]-l_r[a-1])
