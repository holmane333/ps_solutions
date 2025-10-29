import sys;input=lambda:sys.stdin.readline().rstrip()
MX, MN = int(1e9), 0

class SegTree:
    def __init__(self, n: int):
        self.n = n
        self.tree = [0] * (self.n << 2)
        self.lazy_min = [MX] * (self.n << 2)
        self.lazy_max = [MN] * (self.n << 2)

    def _update_lazy(self, node: int, start: int, end: int):
        if (start != end):
            self.lazy_max[node << 1] = max(self.lazy_max[node << 1], self.lazy_max[node])
            self.lazy_max[(node << 1) | 1] = max(self.lazy_max[(node << 1) | 1], self.lazy_max[node])
            self.lazy_max[node << 1] = min(self.lazy_max[node << 1], self.lazy_min[node])
            self.lazy_max[(node << 1) | 1] = min(self.lazy_max[(node << 1) | 1], self.lazy_min[node])
            
            self.lazy_min[node << 1] = max(self.lazy_min[node << 1], self.lazy_max[node])
            self.lazy_min[(node << 1) | 1] = max(self.lazy_min[(node << 1) | 1], self.lazy_max[node])
            self.lazy_min[node << 1] = min(self.lazy_min[node << 1], self.lazy_min[node])
            self.lazy_min[(node << 1) | 1] = min(self.lazy_min[(node << 1) | 1], self.lazy_min[node])
        else:
            self.tree[node] = max(min(self.tree[node], self.lazy_min[node]), self.lazy_max[node])
        self.lazy_max[node], self.lazy_min[node] = MN, MX
            

    def _range_update(self, node: int, start: int, end: int, left: int, right: int, op: int, diff: int):
        self._update_lazy(node, start, end)
        if (right < start or left > end): return
        if (left <= start and end <= right):
            if (op == 1):
                self.lazy_max[node] = max(self.lazy_max[node], diff)
                self.lazy_min[node] = max(self.lazy_min[node], diff)
            else:
                self.lazy_max[node] = min(self.lazy_max[node], diff)
                self.lazy_min[node] = min(self.lazy_min[node], diff)
            self.tree[node] = max(min(self.tree[node], self.lazy_min[node]), self.lazy_max[node])
            return

        mid = (start + end) >> 1
        self._range_update(node << 1, start, mid, left, right, op, diff)
        self._range_update((node << 1) | 1, mid + 1, end, left, right, op, diff)

    def _query(self, node: int, start: int, end: int, left: int, right: int, res: list) -> None:
        self._update_lazy(node, start, end)
        if (start == end):
            self.tree[node] = max(min(self.tree[node], self.lazy_min[node]), self.lazy_max[node])
            res[start] = self.tree[node]
            return
        if right < start or left > end: return
        mid = (start + end) >> 1
        self._query(node << 1, start, mid, left, right, res)
        self._query((node << 1) | 1, mid + 1, end, left, right, res)

    def range_update(self, left: int, right: int, op: int, diff: int) -> None:
        self._range_update(1, 0, self.n - 1, left - 1, right - 1, op, diff)

    def query(self, left: int, right: int) -> list:
        res = [0] * self.n
        self._query(1, 0, self.n - 1, left - 1, right - 1, res)
        return res


n, k = map(int, input().split())
seg_tree = SegTree(n)

for _ in range(k):
    op, left, right, height = map(int, input().split())
    seg_tree.range_update(left + 1, right + 1, op, height)
print('\n'.join(map(str, seg_tree.query(1, n))))