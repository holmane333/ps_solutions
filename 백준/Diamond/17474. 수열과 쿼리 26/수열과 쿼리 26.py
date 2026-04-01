import sys;input=lambda:sys.stdin.readline().rstrip()

N = int(input())
arr = [*map(int, input().split())]

size = 1 << (N - 1).bit_length() + 1
tree = [0] * size
tree2 = [-1] * size
cnt_lazy = [0] * size
tree_sum = [0] * size


def _calculate_value(node):
    left, right = node << 1, node << 1 | 1
    tree_sum[node] = tree_sum[left] + tree_sum[right]

    if tree[left] == tree[right]:
        tree[node] = tree[left]
        tree2[node] = max(tree2[left], tree2[right])
        cnt_lazy[node] = cnt_lazy[left] + cnt_lazy[right]
    elif tree[left] > tree[right]:
        tree[node] = tree[left]
        tree2[node] = max(tree2[left], tree[right])
        cnt_lazy[node] = cnt_lazy[left]
    else:
        tree[node] = tree[right]
        tree2[node] = max(tree[left], tree2[right])
        cnt_lazy[node] = cnt_lazy[right]


def _update_lazy(node):
    parent_max = tree[node]
    left, right = node << 1, node << 1 | 1

    if tree[left] > parent_max:
        tree_sum[left] -= cnt_lazy[left] * (tree[left] - parent_max)
        tree[left] = parent_max
    if tree[right] > parent_max:
        tree_sum[right] -= cnt_lazy[right] * (tree[right] - parent_max)
        tree[right] = parent_max


def _init(node, start, end):
    if start == end:
        tree[node] = tree_sum[node] = arr[start]
        cnt_lazy[node] = 1
        tree2[node] = -1
        return
    mid = (start + end) >> 1
    _init(node << 1, start, mid)
    _init(node << 1 | 1, mid + 1, end)
    _calculate_value(node)


def _range_update(node, start, end, left, right, diff):
    if right < start or left > end or tree[node] <= diff:
        return

    if left <= start and end <= right and tree2[node] < diff:
        tree_sum[node] -= cnt_lazy[node] * (tree[node] - diff)
        tree[node] = diff
        return

    _update_lazy(node)
    mid = (start + end) >> 1
    _range_update(node << 1, start, mid, left, right, diff)
    _range_update(node << 1 | 1, mid + 1, end, left, right, diff)
    _calculate_value(node)


def _query_sum(node, start, end, left, right):
    if right < start or left > end:
        return 0
    if left <= start and end <= right:
        return tree_sum[node]

    _update_lazy(node)
    mid = (start + end) >> 1
    return _query_sum(node << 1, start, mid, left, right) + \
           _query_sum(node << 1 | 1, mid + 1, end, left, right)


def _query_max(node, start, end, left, right):
    if right < start or left > end:
        return 0
    if left <= start and end <= right:
        return tree[node]

    _update_lazy(node)
    mid = (start + end) >> 1
    l_res = _query_max(node << 1, start, mid, left, right)
    r_res = _query_max(node << 1 | 1, mid + 1, end, left, right)
    return l_res if l_res > r_res else r_res

_init(1, 0, N - 1)

res = []
Q = int(input())
for i in range(Q):
    query = [*map(int, input().split())]
    if query[0] == 1:
        L, R, X = query[1:]
        _range_update(1, 0, N - 1, L - 1, R - 1, X)
    elif query[0] == 2:
        L, R = query[1:]
        res.append(str(_query_max(1, 0, N - 1, L - 1, R - 1)))
    else:
        L, R = query[1:]
        res.append(str(_query_sum(1, 0, N - 1, L - 1, R - 1)))
print('\n'.join(res))