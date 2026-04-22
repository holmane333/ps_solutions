import sys;input=lambda:sys.stdin.readline().rstrip()

def ccw(i, j, k):
    area2 = (j[1] - i[1]) * (k[2] - i[2]) - (j[2] - i[2]) * (k[1] - i[1])
    if (area2 > 0): return 1
    elif (area2 < 0): return -1
    return 0

def grahamScan(points):
    point = sorted(points, key=lambda x: (x[1], x[2]))
    if len(point) <= 2:
        return point
    
    left = []
    for i in point:
        while (len(left) >= 2 and ccw(left[-2], left[-1], i) <= 0):
            left.pop()
        left.append(i)
        
    right = []
    for i in reversed(point):
        while (len(right) >= 2 and ccw(right[-2], right[-1], i) <= 0):
            right.pop()
        right.append(i)
        
    return left[:-1] + right[:-1]

def solve():
    line = input()
    if not line: return
    n = int(line)
    
    points = []
    for i in range(n):
        x, y = map(int, input().split())
        points.append((i + 1, x, y))
    
    hull = grahamScan(points)
    
    hull_indices = set()
    for p in hull:
        hull_indices.add(p[0])
        
    if len(hull_indices) < n:
        for p in points:
            if p[0] not in hull_indices:
                print(1)
                print(p[0])
                return

    print(2)
    print(f"{hull[0][0]} {hull[2][0]}")

solve()