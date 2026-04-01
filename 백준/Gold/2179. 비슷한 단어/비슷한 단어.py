import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
origin = [input() for _ in range(N)]
words = []
for i in range(N):
    words.append((origin[i], i))
words.sort()

res = 0
idx = 0
length_pre = [0] * N
for i in range(N - 1):
    cnt = 0
    while (cnt < min(len(words[i][0]), len(words[i + 1][0]))):
        if (words[i][0][cnt] != words[i + 1][0][cnt]): break
        cnt += 1
    if (res < cnt):
        res = cnt
    length_pre[words[i][1]] = max(length_pre[words[i][1]], cnt)
    length_pre[words[i + 1][1]] = max(length_pre[words[i + 1][1]], cnt)

prefix = ""
pos = 0
for i in range(N):
    if length_pre[i] == res:
        prefix = origin[i][:res]
        print(origin[i])
        pos = i + 1
        break

for i in range(pos, N):
    if origin[i].startswith(prefix):
        print(origin[i])
        break
