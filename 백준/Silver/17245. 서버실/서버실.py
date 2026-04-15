import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
ary = [[*map(int, input().split())] for i in range(N)]

def check(t):
    count = 0
    for i in range(N):
        for j in range(N):
            count += min(t, ary[i][j])
    return count >= total

total = sum(sum(ary[i]) for i in range(N)) + 1
total >>= 1
left, right = 0, int(1e7) + 1
ans = right
while (left <= right):
    mid = (left + right) >> 1
    if (check(mid)):
        ans = min(ans, mid)
        right = mid - 1
    else: left = mid + 1
print(ans)

