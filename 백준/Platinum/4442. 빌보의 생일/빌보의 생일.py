import sys;input_data=lambda:sys.stdin.readline().split()

n = 0
find_ary = dict()
ary = [0] * 1000002
seg_tree = [0] * 2097154

def update(node, start, end, index, diff):
    if index < start or index > end:
        return
    seg_tree[node] = seg_tree[node] + diff
    if start != end:
        update(node * 2, start, (start + end) // 2, index, diff)
        update(node * 2 + 1, (start + end) // 2 + 1, end, index, diff)

def sum_tree(node, start, end, left, right):
    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return seg_tree[node]
    return sum_tree(node * 2, start, (start + end) // 2, left, right) + \
           sum_tree(node * 2 + 1, (start + end) // 2 + 1, end, left, right)

sum = sum_tree

def solve():
    global n, m, k, seg_tree
    
    res = []
    while (True):
        n = int(input())
        if (not n): break
        
        find_ary = dict()
        l1, l2 = [0] + list(input().split()), [0] + list(input().split())
        # assert(l1[1] == 'Frodo')
        seg_tree = [0] * 2097154
        
        for i in range(1, n + 1):
            find_ary[l1[i]] = i
            
        for i in range(1, n + 1):
            ary[i] = find_ary[l2[i]]
        
        ans = 0
        for i in range(1, n + 1):
            # print(ans)
            ans += sum(1, 1, n, ary[i] + 1, n)
            update(1, 1, n, ary[i], 1)
        res.append(str(ans))
    print('\n'.join(res))

solve()