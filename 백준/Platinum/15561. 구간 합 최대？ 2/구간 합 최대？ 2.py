import sys;input=lambda:sys.stdin.readline().rstrip()

class SegTree:
    def __init__(self, n):
        size = 1
        while size < n:
            size <<= 1
        self.size = size
        self.data = [0] * (size + size)
        self.lval = [0] * (size + size)
        self.rval = [0] * (size + size)
        self.val = [0] * (size + size)

    def update(self, pos:int, val:int) -> None:
        node = pos + self.size
        self.data[node] = val
        self.lval[node] = val
        self.rval[node] = val
        self.val[node] = val
        node >>= 1
        while node:
            self._pull(node)
            node >>= 1

    def _pull(self, node:int) -> None:
        lc, rc = node << 1, (node << 1) | 1
        self.data[node] = self.data[lc] + self.data[rc]
        self.lval[node] = max(self.lval[lc], self.data[lc] + self.lval[rc])
        self.rval[node] = max(self.rval[rc], self.rval[lc] + self.data[rc])
        self.val[node] = max(self.val[lc], self.val[rc], self.rval[lc] + self.lval[rc])

    # def query(self, l:int, r:int) -> tuple:
    #     return self._query(1, 0, self.size - 1, l, r)

    # def _query(self, node:int, start:int, end:int, l:int, r:int) -> tuple:
    #     if r < start or end < l:
    #         return (0, -10**18, -10**18, -10**18)
    #     if l <= start and end <= r:
    #         return (self.data[node], self.lval[node], self.rval[node], self.val[node])
    #     mid = (start + end) >> 1
    #     left = self._query(node << 1, start, mid, l, r)
    #     right = self._query((node << 1) | 1, mid + 1, end, l, r)

    #     all_sum = left[0] + right[0]
    #     lval = max(left[1], left[0] + right[1])
    #     rval = max(right[2], right[0] + left[2])
    #     val = max(left[3], right[3], left[2] + right[1])
    #     return (all_sum, lval, rval, val)
    
    def _merge(self, left, right):
        all_sum = left[0] + right[0]
        lval = max(left[1], left[0] + right[1])
        rval = max(right[2], right[0] + left[2])
        val = max(left[3], right[3], left[2] + right[1])
        return (all_sum, lval, rval, val)

    def query(self, l: int, r: int) -> tuple:
        l += self.size
        r += self.size + 1
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

N, Q, U, V = map(int, input().split())
l = [0] + list(map(int, input().split()))

seg = SegTree(N + 5)
for i in range(1, N + 1):
    seg.update(i, l[i] * U + V)

for _ in range(Q):
    c, a, b = map(int, input().split())
    if (c): seg.update(a, b * U + V)
    else: print(seg.query(a, b)[3] - V)
