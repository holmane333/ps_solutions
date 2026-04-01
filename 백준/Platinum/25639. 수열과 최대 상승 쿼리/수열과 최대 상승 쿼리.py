import sys;input=lambda:sys.stdin.readline().rstrip()

class SegTree:
    def __init__(self, n):
        size = 1
        while size < n:
            size <<= 1
        self.size = size
        self.data1 = [-float('inf')] * (size + size)
        self.data2 = [float('inf')] * (size + size)
        self.inc = [0] * (size + size)

    def update(self, pos:int, val:int) -> None:
        node = pos + self.size
        self.data1[node] = val
        self.data2[node] = val
        self.inc[node] = 0
        node >>= 1
        while node:
            self._pull(node)
            node >>= 1

    def _pull(self, node:int) -> None:
        lc, rc = node << 1, (node << 1) | 1
        self.data1[node] = max(self.data1[lc], self.data1[rc])
        self.data2[node] = min(self.data2[lc], self.data2[rc])
        self.inc[node] = max(self.inc[lc], self.inc[rc], self.data1[rc] - self.data2[lc])

    def _merge(self, left, right):
        maxval = max(left[0], right[0])
        minval = min(left[1], right[1])
        inc = max(left[2], right[2], right[0] - left[1])
        return (maxval, minval, inc)
    
    def query(self, l: int, r: int) -> tuple:
        l += self.size
        r += self.size + 1
        res_left = (-10**18, 10**18, 0)
        res_right = (-10**18, 10**18, 0)
        while l < r:
            if l & 1:
                res_left = self._merge(res_left, (self.data1[l], self.data2[l], self.inc[l]))
                l += 1
            if r & 1:
                r -= 1
                res_right = self._merge((self.data1[r], self.data2[r], self.inc[r]), res_right)
            l >>= 1
            r >>= 1
        return self._merge(res_left, res_right)[2]
 
N = int(input())
l = [0] + list(map(int, input().split()))
Q = int(input())

seg = SegTree(N + 5)
for i in range(1, N + 1):
    seg.update(i, l[i])

res = []
for _ in range(Q):
    c, a, b = map(int, input().split())
    if (c == 1): seg.update(a, b)
    else: res.append(str(seg.query(a, b)))
print('\n'.join(res))