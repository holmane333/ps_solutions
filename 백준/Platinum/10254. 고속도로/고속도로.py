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
    point = sorted(points, key=lambda x:(x[1], x[0]))
    left, right = [], []
    for i in point:
        while (len(left) >= 2 and ccw(left[-2], left[-1], i) <= 0): left.pop()
        left.append(i)
    for i in reversed(point):
        while (len(right) >= 2 and ccw(right[-2], right[-1], i) <= 0): right.pop()
        right.append(i)
    return left[:-1] + right[:-1]

def rotatingCalipers(points: list) -> tuple:
    l_point, r_point = 0, 0
    size = len(points)
    for i in range(1, size):
        if (points[l_point][0] < points[i][0]): l_point = i
        if (points[r_point][0] > points[i][0]): r_point = i
    
    p1, p2 = l_point, r_point
    res = dist(points[l_point], points[r_point])
    for i in range(size):
        v1, v2 = [points[(l_point + 1) % size][0] - points[l_point][0], points[(l_point + 1) % size][1] - points[l_point][1]], [points[(r_point + 1) % size][0] - points[r_point][0], points[(r_point + 1) % size][1] - points[r_point][1]]
        if (ccw2(v1, v2) >= 0): r_point = (r_point + 1) % size
        else: l_point = (l_point + 1) % size
        d = dist(points[l_point], points[r_point])
        if (d > res):
            res = d
            p1, p2 = l_point, r_point
    return p1, p2

for _ in range(int(input())):
    N = int(input())
    l = [list(map(int, input().split())) for i in range(N)]
    convex_hull = grahamScan(l)
    p1, p2 = rotatingCalipers(convex_hull)
    print(' '.join(map(str, (convex_hull[p1] + convex_hull[p2]))))