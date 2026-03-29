import sys;input=lambda:sys.stdin.readline().rstrip()

def update(node, start, end, index, diff, seg_tree):
    if index < start or index > end:
        return
    seg_tree[node] += diff
    if start != end:
        mid = (start + end) >> 1
        update(node << 1, start, mid, index, diff, seg_tree)
        update((node << 1) | 1, mid + 1, end, index, diff, seg_tree)

def query_sum(node, start, end, left, right, seg_tree):
    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return seg_tree[node]
    mid = (start + end) >> 1
    return (query_sum(node << 1, start, mid, left, right, seg_tree) + 
            query_sum((node << 1) | 1, mid + 1, end, left, right, seg_tree))

def solve():
    n = int(input())
    p = list(map(int, input().split()))
    
    k_idx = n - 1
    for i in range(n - 1, 0, -1):
        if p[i-1] < p[i]:
            k_idx = i - 1
        else:
            break
            
    k = k_idx
    print(k)
    
    if k == 0:
        return

    seg_tree = [0] * (4 * n + 1)
    for i in range(k_idx, n):
        update(1, 1, n, p[i], 1, seg_tree)
        
    res = []
    for i in range(k):
        dist = (k - 1 - i) + query_sum(1, 1, n, 1, p[i] - 1, seg_tree)
        res.append(dist)
        update(1, 1, n, p[i], 1, seg_tree)
        
    print(*(res))

solve()