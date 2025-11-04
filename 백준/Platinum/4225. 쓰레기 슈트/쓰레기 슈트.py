import sys;input=lambda:sys.stdin.readline().rstrip()
import math

def ccw(i, j, k):
    area2 = (j[0] - i[0]) * (k[1] - i[1]) - (j[1] - i[1]) * (k[0] - i[0])
    return area2

def ccw2(i: list, j: list) -> int:
    result = i[0] * j[1] - i[1] * j[0]
    return result

def dist(p1: list, p2: list) -> float:
    return math.sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]))

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

def rotatingCalipers(points: list) -> int:
    size = len(points)
    res = 1e18
    for i in range(size):
        p1, p2 = i, (i + 1) % size
        res1 = 0
        d = dist(points[p1], points[p2])
        for j in range(size):
            if (j == p1 or j == p2): continue
            res1 = max(res1, abs(ccw(points[p1], points[p2], points[j]) / d))
        res = min(res, res1)
    return math.ceil(res * 100) / 100

res = []
idx = 1
while (1):
    N = int(input())
    if (not N): break
    l = [list(map(int, input().split())) for i in range(N)]
    convex_hull = grahamScan(l)
    res.append(f'Case {idx}: {rotatingCalipers(convex_hull):.2f}')
    idx += 1
print('\n'.join(res))