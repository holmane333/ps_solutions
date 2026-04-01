from sys import stdin

class SegTree:
    def __init__(self, n):
        size = 1
        while size < n:
            size <<= 1
        self.n = n
        self.size = size
        self.data = [[0, 0] for _ in range(2 * size)]

    def query(self, val):
        if self.data[1][0] < val:
            return self.data[1]
        res_sum, res_cnt = 0, 0
        v = 1
        while v < self.size:
            left = self.data[v * 2]
            if res_sum + left[0] >= val:
                v = v * 2
            else:
                res_sum += left[0]
                res_cnt += left[1]
                v = v * 2 + 1
        res_sum += self.data[v][0]
        res_cnt += self.data[v][1]
        return res_sum, res_cnt

    def update(self, pos, val):
        v = pos + self.size - 1
        self.data[v] = [val, 1]
        v //= 2
        while v:
            left = self.data[v * 2]
            right = self.data[v * 2 + 1]
            self.data[v] = [left[0] + right[0], left[1] + right[1]]
            v //= 2


N, Q = map(int, stdin.readline().split())
l = [[v, i + 1] for i, v in enumerate(list(map(int, stdin.readline().split())))]
seg = SegTree(N + 5)

l.sort(key=lambda x:(-x[0], x[1]))
l = [[0, 0]] + l
d = {v[1]: i for i, v in enumerate(l[1:], start=1)}
q = [list(map(int, stdin.readline().split())) + [i] for i in range(Q)]
q.sort()

res = ['-1'] * Q
tmp = 1
for a, b, idx in q:
    while (tmp <= a):
        seg.update(d[tmp], l[d[tmp]][0])
        tmp += 1
    
    total, cnt = seg.query(b)
    if (total >= b):
        res[idx] = str(cnt)

print("\n".join(res))