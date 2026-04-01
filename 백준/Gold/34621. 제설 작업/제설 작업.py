import sys;input=lambda:sys.stdin.readline().rstrip()
from collections import deque

n, m = map(int, input().split())
l = [list(map(int, input().split())) for i in range(n)]

row_s = [sum(i) for i in l]
col_s = [sum(l[i][j] for i in range(n)) for j in range(m)]

def check(mid: int) -> bool:
    rows = row_s.copy()
    cols = col_s.copy()
    
    q = deque()
    
    vr = [0 for i in range(n)]
    vc = [0 for i in range(m)]
    cnt = 0
    
    for i in range(n):
        if (rows[i] <= mid): q.append((0, i)); vr[i] = 1
    for i in range(m):
        if (cols[i] <= mid): q.append((1, i)); vc[i] = 1
    
    while (q):
        a, b = q.popleft()
        cnt += 1
        if (a):
            for i in range(n):
                rows[i] -= l[i][b]
                if (not vr[i] and rows[i] <= mid):
                    q.append((0, i))
                    vr[i] = 1
        else:
            for i in range(m):
                cols[i] -= l[b][i]
                if (not vc[i] and cols[i] <= mid):
                    q.append((1, i))
                    vc[i] = 1
    if (cnt == n + m): return True
    else: return False
        


left, right = 1, max(max(row_s), max(col_s))
res = right
while (left <= right):
    mid = (left + right) // 2
    if (check(mid)):
        res = mid
        right = mid - 1
    else: left = mid + 1

print(res)