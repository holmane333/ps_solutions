import sys;input=lambda:sys.stdin.readline().rstrip()
# floor(sqrt(x)) = int(x ** 0.5)

N, Q = map(int, input().split())
arr = [*map(int, input().split())]

size = 4 * N
max_value = [0] * size
min_value = [0] * size
tree_sum = [0] * size

lazy = [0] * size


def _calculate_value(node):
    left, right = node << 1, node << 1 | 1

    max_value[node] = max(max_value[left], max_value[right])
    min_value[node] = min(min_value[left], min_value[right])
    tree_sum[node] = tree_sum[left] + tree_sum[right]

def _apply(node, start, end, val):
    max_value[node] += val
    min_value[node] += val
    tree_sum[node] += (end - start + 1) * val
    lazy[node] += val

def _update_lazy(node, start, end):
    if lazy[node] != 0:
        mid = (start + end) >> 1
        _apply(node << 1, start, mid, lazy[node])
        _apply((node << 1) + 1, mid + 1, end, lazy[node])
        lazy[node] = 0

def _init(node, start, end):
    if start == end:
        max_value[node] = min_value[node] = tree_sum[node] = arr[start]
        return
    mid = (start + end) >> 1
    _init(node << 1, start, mid)
    _init(node << 1 | 1, mid + 1, end)
    _calculate_value(node)


# def _range_update(node, start, end, left, right, diff):
#     if right < start or left > end or tree[node] <= diff:
#         return
#
#     if left <= start and end <= right and tree2[node] < diff:
#         tree_sum[node] -= cnt_lazy[node] * (tree[node] - diff)
#         tree[node] = diff
#         return
#
#     _update_lazy(node)
#     mid = (start + end) >> 1
#     _range_update(node << 1, start, mid, left, right, diff)
#     _range_update(node << 1 | 1, mid + 1, end, left, right, diff)
#     _calculate_value(node)

def _range_update_plus(node, start, end, left, right, diff):
    if right < start or left > end:
        return

    if left <= start and end <= right:
        _apply(node, start, end, diff)
        return

    _update_lazy(node, start, end)
    mid = (start + end) >> 1
    _range_update_plus(node << 1, start, mid, left, right, diff)
    _range_update_plus(node << 1 | 1, mid + 1, end, left, right, diff)
    _calculate_value(node)


def _range_update_div(node, start, end, left, right, diff):
    if right < start or left > end:
        return

    if left <= start and end <= right:
        if max_value[node] // diff - max_value[node] == min_value[node] // diff - min_value[node]:
            _apply(node, start, end, max_value[node] // diff - max_value[node])
            return

    _update_lazy(node, start, end)
    mid = (start + end) >> 1
    _range_update_div(node << 1, start, mid, left, right, diff)
    _range_update_div(node << 1 | 1, mid + 1, end, left, right, diff)
    _calculate_value(node)


def _query_sum(node, start, end, left, right):
    if right < start or left > end:
        return 0
    if left <= start and end <= right:
        return tree_sum[node]

    _update_lazy(node, start, end)
    mid = (start + end) >> 1
    return _query_sum(node << 1, start, mid, left, right) + \
           _query_sum(node << 1 | 1, mid + 1, end, left, right)


def _query_max(node, start, end, left, right):
    if right < start or left > end:
        return -10**18
    if left <= start and end <= right:
        return max_value[node]

    _update_lazy(node, start, end)
    mid = (start + end) >> 1
    return max(_query_max(node << 1, start, mid, left, right),
           _query_max(node << 1 | 1, mid + 1, end, left, right))


_init(1, 0, N - 1)

res = []
for i in range(Q):
    query = [*map(int, input().split())]
    if query[0] == 0:
        L, R, X = query[1:]
        _range_update_plus(1, 0, N - 1, L, R, X)
    elif query[0] == 1:
        L, R, D = query[1:]
        _range_update_div(1, 0, N - 1, L, R, D)
    else:
        L, R, X = query[1:]
        res.append(str(_query_max(1, 0, N - 1, L, R)))
print('\n'.join(res))
