import sys;input=lambda:sys.stdin.readline().rstrip()

def build(node, start, end, w, tree):
    if start == end:
        tree[node] = w
        return
    mid = (start + end) >> 1
    build(node << 1, start, mid, w, tree)
    build((node << 1) | 1, mid + 1, end, w, tree)
    tree[node] = max(tree[node << 1], tree[(node << 1) | 1])

def query(node, start, end, val, tree):
    if tree[node] < val: return -1
    
    if start == end:
        tree[node] -= val
        return start

    mid = (start + end) >> 1
    if tree[node << 1] >= val: res = query(node << 1, start, mid, val, tree)
    else: res = query((node << 1) | 1, mid + 1, end, val, tree)
    tree[node] = max(tree[node << 1], tree[(node << 1) | 1])
    return res

def solve():
    h, w, n = map(int, input().split())

    # assert(not ((h, w, n) == (3, 5, 5)))
    h = min(h, n)
    tree = [0] * (4 * h + 1)
    
    build(1, 1, h, w, tree)
    
    res = []
    for _ in range(n):
        q = int(input())
        res.append(str(query(1, 1, h, q, tree)))
    print('\n'.join(res))

solve()