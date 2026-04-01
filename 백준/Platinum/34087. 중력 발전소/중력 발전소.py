from sys import stdin
import bisect

class SegTree:
    def __init__(self, n):
        size = 1
        while size < n:
            size <<= 1
        self.size = size
        self.data = [0 for i in range(2 * size)]
        self.cnt = [0 for i in range(2 * size)]

    def update(self, pos, val):
        v = pos + self.size
        self.data[v] += val
        self.cnt[v] += 1
        v //= 2
        while v:
            self.data[v] = self.data[v * 2] + self.data[v * 2 + 1]
            self.cnt[v] = self.cnt[v * 2] + self.cnt[v * 2 + 1]
            v //= 2

    def query(self, l, r):
        res = cnt = 0
        l += self.size
        r += self.size
        while l < r:
            if l & 1:
                res += self.data[l]
                cnt += self.cnt[l]
                l += 1
            if r & 1:
                r -= 1
                res += self.data[r]
                cnt += self.cnt[r]
            l //= 2
            r //= 2
        return cnt, res

N, M, K = map(int, stdin.readline().split())
A = list(map(int, stdin.readline().split()))

pre = [0 for i in range(N + 1)]
for i in range(1, N + 1):
    pre[i] = pre[i - 1] + A[i - 1]
vall = [pre[i] - K * i for i in range(N + 1)]
l = sorted(set(vall))
idx = {v : i for i, v in enumerate(l)}
res = 0

def func(X):
    seg = SegTree(len(l))
    
    cnt_all = 0
    sum_all = 0
    
    for j in vall:
        t = j - X
        if (t < l[0]): pos = 0
        else: pos = bisect.bisect_right(l, t)
        if pos > 0:
            cnt, s = seg.query(0, pos)
            cnt_all += cnt
            sum_all += cnt * j - s
        seg.update(idx[j], j)
    
    return cnt_all, sum_all

lt, rt = 0, max(A) * N
X = 0
while lt <= rt:
    m = (lt + rt) // 2
    cnt, tmp = func(m)
    if cnt >= M:
        X = m
        lt = m + 1
    else:
        rt = m - 1

cnt, s = func(X)
res = pre[N] + s - (cnt - M) * X

print(res)
