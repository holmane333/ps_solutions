import sys;input=lambda:sys.stdin.readline().rstrip()

def build(node, start, end, w, tree):
    if start == end:
        tree[node] = w[start - 1]
        return
    mid = (start + end) >> 1
    build(node << 1, start, mid, w, tree)
    build((node << 1) | 1, mid + 1, end, w, tree)
    tree[node] = tree[node << 1] + tree[(node << 1) | 1]

def query(node, start, end, val, tree):
    if start == end:
        tree[node] = 0
        return start

    mid = (start + end) >> 1
    if tree[node << 1] >= val: 
        res = query(node << 1, start, mid, val, tree)
    else: 
        res = query((node << 1) | 1, mid + 1, end, val - tree[node << 1], tree)
        
    tree[node] = tree[node << 1] + tree[(node << 1) | 1]
    return res

def solve():
    n = int(input())
    w = list(map(int, input().split()))
    p = list(map(int, input().split()))

    tree = [0] * (4 * n + 1)
    
    build(1, 1, n, w, tree)
    
    res = []
    for val in p:
        res.append(str(query(1, 1, n, val, tree)))
        
    print(' '.join(res))

solve()