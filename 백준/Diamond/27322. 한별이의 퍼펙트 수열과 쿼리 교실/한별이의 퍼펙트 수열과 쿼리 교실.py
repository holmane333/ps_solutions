import sys;input=lambda:sys.stdin.readline().rstrip()
INF = int(2e18)

N = int(input())
arr = [*map(int, input().split())]

size = 4 * N
max_tree = [0] * size   # 1번째로 큰 값 tree
max2_tree = [0] * size  # 2번째로 큰 값 tree
min_tree = [0] * size   # 1번째로 작은 값 tree
min2_tree = [0] * size  # 2번째로 작은 값 tree
sum_tree = [0] * size  # sum 처리에 대한 tree
plus_lazy = [0] * size  # + 연산에 대한 A의 lazy 값

cnt_max = [0] * size  # 1번째로 큰 값 개수
cnt_min = [0] * size  # 1번째로 작은 값 개수

# b_tree = [0] * size       # B 값에 대한 tree
# b_plus_lazy = [0] * size  # + 연산에 대한 B의 lazy 값
# b_max_lazy = [0] * size   # max 연산에 대한 B의 lazy 값
# b_min_lazy = [0] * size   # min 연산에 대한 B의 lazy 값


# def _calculate_value(node):
#     left, right = node << 1, node << 1 | 1
#     tree_sum[node] = tree_sum[left] + tree_sum[right]
#
#     if tree[left] == tree[right]:
#         tree[node] = tree[left]
#         tree2[node] = max(tree2[left], tree2[right])
#         cnt_lazy[node] = cnt_lazy[left] + cnt_lazy[right]
#     elif tree[left] > tree[right]:
#         tree[node] = tree[left]
#         tree2[node] = max(tree2[left], tree[right])
#         cnt_lazy[node] = cnt_lazy[left]
#     else:
#         tree[node] = tree[right]
#         tree2[node] = max(tree[left], tree2[right])
#         cnt_lazy[node] = cnt_lazy[right]


def _push_up(node):
    left, right = node << 1, node << 1 | 1

    if max_tree[left] == max_tree[right]:
        max_tree[node] = max_tree[left]
        max2_tree[node] = max(max2_tree[left], max2_tree[right])
        cnt_max[node] = cnt_max[left] + cnt_max[right]
    else:
        if max_tree[left] < max_tree[right]:
            left, right = right, left
        max_tree[node] = max_tree[left]
        max2_tree[node] = max(max2_tree[left], max_tree[right])
        cnt_max[node] = cnt_max[left]

    if min_tree[left] == min_tree[right]:
        min_tree[node] = min_tree[left]
        min2_tree[node] = min(min2_tree[left], min2_tree[right])
        cnt_min[node] = cnt_min[left] + cnt_min[right]
    else:
        if min_tree[left] > min_tree[right]:
            left, right = right, left
        min_tree[node] = min_tree[left]
        min2_tree[node] = min(min2_tree[left], min_tree[right])
        cnt_min[node] = cnt_min[left]

    sum_tree[node] = sum_tree[left] + sum_tree[right]
    # b_tree[node] = b_tree[left] + b_tree[right]


# def _apply(node, start, end, val):
#     max_value[node] += val
#     min_value[node] += val
#     tree_sum[node] += (end - start + 1) * val
#     lazy[node] += val


def _apply_plus(node, start, end, val_a):
    max_tree[node] += val_a
    if max2_tree[node] != -INF:
        max2_tree[node] += val_a

    min_tree[node] += val_a
    if min2_tree[node] != INF:
        min2_tree[node] += val_a

    sum_tree[node] += val_a * (end - start + 1)
    
    plus_lazy[node] += val_a
    # b_tree[node] += val_b * (end - start + 1)
    # b_plus_lazy[node] += val_b


def _apply_min(node, limit):
    if max_tree[node] <= limit: return

    # b_tree[node] += cnt_max[node] * val_b
    # b_min_lazy[node] += val_b

    sum_tree[node] -= cnt_max[node] * (max_tree[node] - limit)
    
    if min_tree[node] == max_tree[node]: min_tree[node] = limit
    if min2_tree[node] == max_tree[node]: min2_tree[node] = limit
    max_tree[node] = limit


def _apply_max(node, limit):
    if min_tree[node] >= limit: return

    # b_tree[node] += cnt_min[node] * val_b
    # b_max_lazy[node] += val_b
    
    sum_tree[node] -= cnt_min[node] * (min_tree[node] - limit)

    if max_tree[node] == min_tree[node]: max_tree[node] = limit
    if max2_tree[node] == min_tree[node]: max2_tree[node] = limit
    min_tree[node] = limit


def _push_down(node, start, end):
    mid = (start + end) >> 1
    left, right = node << 1, node << 1 | 1

    # if plus_lazy[node] != 0 or b_plus_lazy[node] != 0:
    #     _apply_plus(left, start, mid, plus_lazy[node], b_plus_lazy[node])
    #     _apply_plus(right, mid + 1, end, plus_lazy[node], b_plus_lazy[node])
    #     plus_lazy[node] = b_plus_lazy[node] = 0

    # if max_tree[left] > max_tree[node]:
    #     _apply_min(left, max_tree[node], b_min_lazy[node])
    # elif b_min_lazy[node] and max_tree[left] == max_tree[node]:
    #     b_tree[left] += cnt_max[left] * b_min_lazy[node]
    #     b_min_lazy[left] += b_min_lazy[node]

    # if max_tree[right] > max_tree[node]:
    #     _apply_min(right, max_tree[node], b_min_lazy[node])
    # elif b_min_lazy[node] and max_tree[right] == max_tree[node]:
    #     b_tree[right] += cnt_max[right] * b_min_lazy[node]
    #     b_min_lazy[right] += b_min_lazy[node]
    # b_min_lazy[node] = 0

    # if min_tree[left] < min_tree[node]:
    #     _apply_max(left, min_tree[node], b_max_lazy[node])
    # elif b_max_lazy[node] and min_tree[left] == min_tree[node]:
    #     b_tree[left] += cnt_min[left] * b_max_lazy[node]
    #     b_max_lazy[left] += b_max_lazy[node]

    # if min_tree[right] < min_tree[node]:
    #     _apply_max(right, min_tree[node], b_max_lazy[node])
    # elif b_max_lazy[node] and min_tree[right] == min_tree[node]:
    #     b_tree[right] += cnt_min[right] * b_max_lazy[node]
    #     b_max_lazy[right] += b_max_lazy[node]
    # b_max_lazy[node] = 0

    if plus_lazy[node] != 0:
        _apply_plus(left, start, mid, plus_lazy[node])
        _apply_plus(right, mid + 1, end, plus_lazy[node])
        plus_lazy[node] = 0

    if max_tree[left] > max_tree[node]:
        _apply_min(left, max_tree[node])
    # elif b_min_lazy[node] and max_tree[left] == max_tree[node]:
    #     b_tree[left] += cnt_max[left] * b_min_lazy[node]
    #     b_min_lazy[left] += b_min_lazy[node]

    if max_tree[right] > max_tree[node]:
        _apply_min(right, max_tree[node])
    # elif b_min_lazy[node] and max_tree[right] == max_tree[node]:
    #     b_tree[right] += cnt_max[right] * b_min_lazy[node]
    #     b_min_lazy[right] += b_min_lazy[node]
    # b_min_lazy[node] = 0

    if min_tree[left] < min_tree[node]:
        _apply_max(left, min_tree[node])
    # elif b_max_lazy[node] and min_tree[left] == min_tree[node]:
    #     b_tree[left] += cnt_min[left] * b_max_lazy[node]
    #     b_max_lazy[left] += b_max_lazy[node]

    if min_tree[right] < min_tree[node]:
        _apply_max(right, min_tree[node])
    # elif b_max_lazy[node] and min_tree[right] == min_tree[node]:
    #     b_tree[right] += cnt_min[right] * b_max_lazy[node]
    #     b_max_lazy[right] += b_max_lazy[node]
    # b_max_lazy[node] = 0


def _init(node, start, end):
    if start == end:
        max_tree[node] = min_tree[node] = sum_tree[node] = arr[start]
        cnt_max[node] = cnt_min[node] = 1
        max2_tree[node] = -INF
        min2_tree[node] = INF
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


def _range_update_plus(node, start, end, left, right, diff):
    if right < start or left > end:
        return

    if left <= start and end <= right:
        _apply_plus(node, start, end, diff)
        return

    _push_down(node, start, end)
    mid = (start + end) >> 1
    _range_update_plus(node << 1, start, mid, left, right, diff)
    _range_update_plus(node << 1 | 1, mid + 1, end, left, right, diff)
    _push_up(node)


def _range_update_max(node, start, end, left, right, diff):
    if right < start or left > end or min_tree[node] >= diff:
        return

    if left <= start and end <= right and min2_tree[node] > diff:
        _apply_max(node, diff)
        return

    _push_down(node, start, end)
    mid = (start + end) >> 1
    _range_update_max(node << 1, start, mid, left, right, diff)
    _range_update_max(node << 1 | 1, mid + 1, end, left, right, diff)
    _push_up(node)


def _range_update_min(node, start, end, left, right, diff):
    if right < start or left > end or max_tree[node] <= diff:
        return

    if left <= start and end <= right and max2_tree[node] < diff:
        _apply_min(node, diff)
        return

    _push_down(node, start, end)
    mid = (start + end) >> 1
    _range_update_min(node << 1, start, mid, left, right, diff)
    _range_update_min(node << 1 | 1, mid + 1, end, left, right, diff)
    _push_up(node)


# def _range_update_sqrt(node, start, end, left, right, diff):
#     if right < start or left > end:
#         return
#
#     if left <= start and end <= right:
#         if max_value[node] // diff - max_value[node] == min_value[node] // diff - min_value[node]:
#             _apply(node, start, end, max_value[node] // diff - max_value[node])
#             return
#
#     _push_down(node, start, end)
#     mid = (start + end) >> 1
#     _range_update_sqrt(node << 1, start, mid, left, right, diff)
#     _range_update_sqrt(node << 1 | 1, mid + 1, end, left, right, diff)
#     _push_up(node)


# def _query_b_sum(node, start, end, left, right):
#     if right < start or left > end:
#         return 0
#     if left <= start and end <= right:
#         return b_tree[node]

#     _push_down(node, start, end)
#     mid = (start + end) >> 1
#     return _query_b_sum(node << 1, start, mid, left, right) + \
#            _query_b_sum(node << 1 | 1, mid + 1, end, left, right)

def _query_sum(node, start, end, left, right):
    if right < start or left > end:
        return 0
    if left <= start and end <= right:
        return sum_tree[node]

    _push_down(node, start, end)
    mid = (start + end) >> 1
    return _query_sum(node << 1, start, mid, left, right) + \
           _query_sum(node << 1 | 1, mid + 1, end, left, right)


def _query_min(node, start, end, left, right):
    if right < start or left > end:
        return INF
    if left <= start and end <= right:
        return min_tree[node]

    _push_down(node, start, end)
    mid = (start + end) >> 1
    return min(_query_min(node << 1, start, mid, left, right),
           _query_min(node << 1 | 1, mid + 1, end, left, right))


def _query_max(node, start, end, left, right):
    if right < start or left > end:
        return -INF
    if left <= start and end <= right:
        return max_tree[node]

    _push_down(node, start, end)
    mid = (start + end) >> 1
    return max(_query_max(node << 1, start, mid, left, right),
           _query_max(node << 1 | 1, mid + 1, end, left, right))


_init(1, 0, N - 1)

res = []
Q = int(input())
for i in range(Q):
    query = [*map(int, input().split())]
    # print(size)
    # print(max_tree)
    # print(max2_tree)
    # print(min_tree)
    # print(min2_tree)
    # print(cnt_max)
    # print(cnt_min)
    # print("B")
    # print(b_tree)
    # print(b_plus_lazy)
    # print(b_max_lazy)
    # print(b_min_lazy)
    # print(query)
    if query[0] == 1:
        if query[3] == 0: continue
        _range_update_min(1, 0, N - 1, query[1] - 1, query[2] - 1, query[3])
    elif query[0] == 2:
        _range_update_max(1, 0, N - 1, query[1] - 1, query[2] - 1, query[3])
    elif query[0] == 3:
        _range_update_plus(1, 0, N - 1, query[1] - 1, query[2] - 1, query[3])
    elif query[0] == 4:
        res.append(str(_query_min(1, 0, N - 1, query[1] - 1, query[2] - 1)))
    elif query[0] == 5:
        res.append(str(_query_max(1, 0, N - 1, query[1] - 1, query[2] - 1)))
    elif query[0] == 6:
        res.append(str(_query_sum(1, 0, N - 1, query[1] - 1, query[2] - 1)))
sys.stdout.write('\n'.join(res) + '\n')
