import sys;input = lambda: sys.stdin.readline().rstrip()

N = int(input())
arr = [*map(int, input().split())]

size = 4 * N
max_tree = [0] * size
and_tree = [0] * size
or_tree = [0] * size

lazy_and = [-1] * size
lazy_or = [0] * size


def _push_up(node):
    left, right = node << 1, node << 1 | 1

    max_tree[node] = max(max_tree[left], max_tree[right])
    and_tree[node] = and_tree[left] & and_tree[right]
    or_tree[node] = or_tree[left] | or_tree[right]


def _apply(node, and_val, or_val):
    max_tree[node] = (max_tree[node] & and_val) | or_val
    and_tree[node] = (and_tree[node] & and_val) | or_val
    or_tree[node] = (or_tree[node] & and_val) | or_val

    lazy_and[node] &= and_val
    lazy_or[node] &= and_val
    lazy_or[node] |= or_val


def _push_down(node):
    if lazy_and[node] == -1 and not lazy_or[node]:
        return
    _apply(node << 1, lazy_and[node], lazy_or[node])
    _apply((node << 1) + 1, lazy_and[node], lazy_or[node])
    lazy_and[node] = -1
    lazy_or[node] = 0


def _init(node, start, end):
    if start == end:
        max_tree[node] = and_tree[node] = or_tree[node] = arr[start]
        return
    mid = (start + end) >> 1
    _init(node << 1, start, mid)
    _init(node << 1 | 1, mid + 1, end)
    _push_up(node)


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


'''
bitwise and operation
break condition
and로 인해 바뀌는 or의 bit가 없는 경우
즉, 바뀌는 값이 없는 경우
-> (or_all & ~x) == 0

tag condition
or이지만 and는 아닌 값(모든 값이 1은 아니나, 어떤 값은 1인 bit)과 and연산으로 인해 바뀌어야 하는 값을 비교했을 때, 겹치는 게 없을 경우
즉, 모든 값이 바뀌어야 하는 경우
((or_all ^ and_all) & ~x) == 0
'''


def _range_update_and(node, start, end, left, right, diff):
    if right < start or left > end or (or_tree[node] & ~diff) == 0:
        return

    if left <= start and end <= right and ((or_tree[node] ^ and_tree[node]) & ~diff) == 0:
        _apply(node, diff, 0)
        return

    _push_down(node)
    mid = (start + end) >> 1
    _range_update_and(node << 1, start, mid, left, right, diff)
    _range_update_and(node << 1 | 1, mid + 1, end, left, right, diff)
    _push_up(node)


'''
bitwise or operation
break condition
and 조건으로 이미 모두 있는 경우
즉, 바뀌는 값이 없는 경우
(and_all & x) == x

tag condition
or이지만 and는 아닌 값(모든 값이 1은 아니나, 어떤 값은 1인 bit)과 or연산으로 인해 바뀌어야 하는 값을 비교했을 때, 겹치는 게 없을 경우
즉, 모든 값이 바뀌어야 하는 경우
((or_all ^ and_all) & x) == 0
'''


def _range_update_or(node, start, end, left, right, diff):
    if right < start or left > end or (and_tree[node] & diff) == diff:
        return

    if left <= start and end <= right and ((or_tree[node] ^ and_tree[node]) & diff) == 0:
        _apply(node, -1, diff)
        return

    _push_down(node)
    mid = (start + end) >> 1
    _range_update_or(node << 1, start, mid, left, right, diff)
    _range_update_or(node << 1 | 1, mid + 1, end, left, right, diff)
    _push_up(node)


# def _query_sum(node, start, end, left, right):
#     if right < start or left > end:
#         return 0
#     if left <= start and end <= right:
#         return tree_sum[node]
#
#     _update_lazy(node, start, end)
#     mid = (start + end) >> 1
#     return _query_sum(node << 1, start, mid, left, right) + \
#            _query_sum(node << 1 | 1, mid + 1, end, left, right)


def _query_max(node, start, end, left, right):
    if right < start or left > end:
        return -10 ** 18
    if left <= start and end <= right:
        return max_tree[node]

    _push_down(node)
    mid = (start + end) >> 1
    return max(_query_max(node << 1, start, mid, left, right),
               _query_max(node << 1 | 1, mid + 1, end, left, right))


_init(1, 0, N - 1)

Q = int(input())
res = []
for i in range(Q):
    query = [*map(int, input().split())]
    if query[0] == 1:
        L, R, X = query[1:]
        _range_update_and(1, 0, N - 1, L - 1, R - 1, X)
    elif query[0] == 2:
        L, R, X = query[1:]
        _range_update_or(1, 0, N - 1, L - 1, R - 1, X)
    else:
        L, R = query[1:]
        res.append(str(_query_max(1, 0, N - 1, L - 1, R - 1)))
print('\n'.join(res))
