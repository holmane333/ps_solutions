from sys import stdin
import sys
from random import randint # , shuffle

n = int(stdin.readline())

l = []
for _ in range(200):
    i, j = randint(1, n), randint(1, n)
    while (i == j):
        j = randint(1, n) 
    print('?', i, j)
    sys.stdout.flush()
    a = int(stdin.readline())
    l.append((i, j, a))

d = dict()
for i in range(len(l)):
    for j in range(len(l)):
        if (i == j): continue
        a, b = l[i], l[j]
        if (a[0] + a[1] - (b[0] + b[1]) == 0): continue
        if ((a[2] - b[2]) % (a[0] + a[1] - (b[0] + b[1]))): continue
        t = abs((a[2] - b[2]) // (a[0] + a[1] - (b[0] + b[1])))
        if (t not in d):
            d[t] = 1
        else:
            d[t] += 1

a, max_v = 0, 0
for key, val in d.items():
    if (max_v < val):
        max_v = val
        a = key

ll = []
for i in l:
    ll.append(i[2] - a * (i[0] + i[1] - 2))

b = min(ll) // 2
k = float('inf')
for i in ll:
    t = i - 2 * b
    if (t == 0): continue
    k = min(k, t)

print('!', a, b, k)
sys.stdout.flush()

# tc = 100
# for q in range(tc):
#     ans_n = randint(1, 125000)
#     n = ans_n * 4
#     ans_a, ans_b, ans_k = randint(1, 1000000000), randint(1, 1000000000), randint(1, 1000000000)
#     rand_idx = [i for i in range(1, n)]
#     shuffle(rand_idx)
#     rand_idx = rand_idx[:ans_n]
#     arr = [0] + [ans_a * i + ans_b for i in range(n)]
#     for i in rand_idx:
#         arr[i] += ans_k

#     # n = 4
#     # ans_a, ans_b, ans_k = 2, 3, 4
#     # arr = [0, 3, 9, 7, 9]
#     # print(n)
#     # print(' ', ans_a, ans_b, ans_k)

#     l = []
    
#     for _ in range(200):
#         i, j = randint(1, n), randint(1, n)
#         while (i == j):
#             j = randint(1, n) 
#         # print('?', i, j, flush=True)
#         sys.stdout.flush()
#         a = arr[i] + arr[j]
#         l.append((i, j, a))

#     d = dict()
#     for i in range(len(l)):
#         for j in range(len(l)):
#             if (i == j): continue
#             a, b = l[i], l[j]
#             if (a[0] + a[1] - (b[0] + b[1]) == 0): continue
#             if ((a[2] - b[2]) % (a[0] + a[1] - (b[0] + b[1]))): continue
#             t = abs((a[2] - b[2]) // (a[0] + a[1] - (b[0] + b[1])))
#             if (t not in d):
#                 d[t] = 1
#             else:
#                 d[t] += 1
#     a, max_v = 1, 0
#     for key, val in d.items():
#         if (max_v < val and key > 0):
#             max_v = val
#             a = key

#     ll = []
#     for i in l:
#         ll.append(i[2] - a * (i[0] + i[1] - 2))
#     # print(l)
#     # print(ll)
#     b = min(ll) // 2
#     k = float('inf')
#     for i in ll:
#         t = i - 2 * b
#         if (t == 0): continue
#         k = min(k, t)
#     # print(ll)

#     # print('!', a, b, k)
#     if ((a, b, k) == (ans_a, ans_b, ans_k)): continue
#     print(d)
#     print(l)
#     print(arr)
#     print(rand_idx)
#     print(n)
#     print(' ', ans_a, ans_b, ans_k)
#     print('!', a, b, k)
#     # sys.stdout.flush()