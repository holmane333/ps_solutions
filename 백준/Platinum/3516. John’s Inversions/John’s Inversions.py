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
    
    cards = [[*map(int, input().split())] for _ in range(n)]
    # assert(not (n == 3 and cards[0][0] == 10 and cards[0][1] == 3))
    cards.sort(key=lambda x: (x[0], x[1]))
    
    ary = []
    for i in range(n):
        ary.append((cards[i][1], i + 1))
        
    ary.sort(key=lambda x: (x[0], x[1]))
    
    seg_tree = [0] * (4 * n + 1)
    res = 0
    
    for i in range(n):
        res += query_sum(1, 1, n, ary[i][1] + 1, n, seg_tree)
        update(1, 1, n, ary[i][1], 1, seg_tree)
        
    print(res)

solve()