import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
res = []
idx, leng = -N, N + 2
for i in range(N + N + 1):
    for j in range(leng):
        if (1 <= idx + j <= N): res.append(f"{2 if i % 2 else 1} {idx + j}")
    idx += 1
print(len(res))
print('\n'.join(res))