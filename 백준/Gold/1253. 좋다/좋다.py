import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
ary = [*map(int, input().split())]

num_count = dict()
hm = dict()

zero_count = 0
for i in range(N):
    if (ary[i] == 0): zero_count += 1
    if (ary[i] not in num_count): num_count[ary[i]] = 0
    num_count[ary[i]] += 1
    hm[ary[i]] = 0

if (zero_count):
    for i in range(N):
        if (ary[i] == 0): continue
        if (num_count[ary[i]] >= 2): hm[ary[i]] = 1

ans = 0
for i in range(N):
    for j in range(i + 1, N):
        if (ary[i] == 0 or ary[j] == 0): continue
        if (ary[i] + ary[j] in hm):
            hm[ary[i] + ary[j]] = 1

if (zero_count >= 3): hm[0] = 1
for i in range(N):
    ans += hm[ary[i]]
print(ans)