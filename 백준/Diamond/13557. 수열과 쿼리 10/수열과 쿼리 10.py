import sys;input=lambda:sys.stdin.readline().rstrip()

class SegTree:
    def __init__(self, n: int):
        size = 1
        while size < n:
            size <<= 1
        self.size = size
        self.data = [0] * (size + size)
        self.lval = [0] * (size + size)
        self.rval = [0] * (size + size)
        self.val = [0] * (size + size)

    def update(self, pos: int, val: int) -> None:
        node = pos + self.size
        self.data[node] = val
        self.lval[node] = val
        self.rval[node] = val
        self.val[node] = val
        node >>= 1
        while node:
            self._pull(node)
            node >>= 1

    def _pull(self, node: int) -> None:
        lc, rc = node << 1, (node << 1) | 1
        self.data[node] = self.data[lc] + self.data[rc]
        self.lval[node] = max(self.lval[lc], self.data[lc] + self.lval[rc])
        self.rval[node] = max(self.rval[rc], self.rval[lc] + self.data[rc])
        self.val[node] = max(self.val[lc], self.val[rc], self.rval[lc] + self.lval[rc])
    
    def _merge(self, left: int, right: int) -> tuple:
        all_sum = left[0] + right[0]
        lval = max(left[1], left[0] + right[1])
        rval = max(right[2], right[0] + left[2])
        val = max(left[3], right[3], left[2] + right[1])
        return (all_sum, lval, rval, val)

    def query(self, l: int, r: int) -> tuple:
        l += self.size
        r += self.size + 1
        if (l > r):
            return (0, 0, 0, 0)
        res_left = (0, -10**18, -10**18, -10**18)
        res_right = (0, -10**18, -10**18, -10**18)
        while l < r:
            if l & 1:
                res_left = self._merge(res_left, (self.data[l], self.lval[l], self.rval[l], self.val[l]))
                l += 1
            if r & 1:
                r -= 1
                res_right = self._merge((self.data[r], self.lval[r], self.rval[r], self.val[r]), res_right)
            l >>= 1
            r >>= 1
        return self._merge(res_left, res_right)

N = int(input())
l = [0] + list(map(int, input().split())) + [0]
pre = [0 for i in range(N + 2)]
for i in range(1, N + 2): pre[i] = pre[i - 1] + l[i]
Q = int(input())

seg = SegTree(N + 5)
for i in range(1, N + 1):
    seg.update(i, l[i])

res = []
for _ in range(Q):
    x1, y1, x2, y2 = map(int, input().split())
    if (y1 < x2): res.append(str(seg.query(x1, y1)[2] + pre[x2 - 1] - pre[y1] + seg.query(x2, y2)[1]))
    else:
        x1x2, x2y1, y1y2 = seg.query(x1, x2 - 1), seg.query(x2, y1), seg.query(y1 + 1, y2)
        res.append(str(max(x1x2[2] + x2y1[1], x2y1[2] + y1y2[1], x2y1[3], x1x2[2] + pre[y1] - pre[x2 - 1] + y1y2[1])))
print('\n'.join(res))