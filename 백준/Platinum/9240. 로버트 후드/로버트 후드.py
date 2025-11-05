import sys;input=lambda:sys.stdin.readline().rstrip()
import math

def ccw(i, j, k):
    area2 = (j[0] - i[0]) * (k[1] - i[1]) - (j[1] - i[1]) * (k[0] - i[0])
    if (area2 > 0): return 1
    elif (area2 < 0): return -1
    return 0

def ccw2(i: list, j: list) -> int:
    result = i[0] * j[1] - i[1] * j[0]
    if result > 0: return 1
    elif result < 0: return -1
    else: return 0

def dist(p1: list, p2: list) -> int:
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])

def grahamScan(points: list) -> list:
    idx = 0
    point = sorted(points, key=lambda x:(x[1], x[0]))
    res = [point[idx]]
    point.pop(idx)

    for i in range(len(point)):
        dy, dx = point[i][1] - res[0][1], point[i][0] - res[0][0]
        point[i] = (point[i][0], point[i][1], math.atan2(dy, dx), dx * dx + dy * dy)
    point.sort(key = lambda p: (p[2], p[3]))
    
    for i in range(len(point)):
        while (len(res) >= 2):
            if (ccw(res[-2], res[-1], point[i]) <= 0): res.pop()
            else: break
        res.append((point[i][0], point[i][1]))
    
    pos = len(res) - 1
    for i in range(pos, 0, -1):
        if (ccw(res[0], res[pos], res[pos - 1]) == 0): pos -= 1
        else: break
    res = res[:pos] + list(reversed(res[pos:]))
    return res

def rotatingCalipers(points: list) -> int:
    l_point, r_point = 0, 0
    size = len(points)
    for i in range(1, size):
        if (points[l_point][0] < points[i][0]): l_point = i
        if (points[r_point][0] > points[i][0]): r_point = i
    
    res = dist(points[l_point], points[r_point])
    for i in range(size):
        v1, v2 = [points[(l_point + 1) % size][0] - points[l_point][0], points[(l_point + 1) % size][1] - points[l_point][1]], [points[(r_point + 1) % size][0] - points[r_point][0], points[(r_point + 1) % size][1] - points[r_point][1]]
        if (ccw2(v1, v2) >= 0): r_point = (r_point + 1) % size
        else: l_point = (l_point + 1) % size
        res = max(res, dist(points[l_point], points[r_point]))
    return res

N = int(input())
l = [list(map(int, input().split())) for i in range(N)]
convex_hull = grahamScan(l)
print(rotatingCalipers(convex_hull) ** 0.5)