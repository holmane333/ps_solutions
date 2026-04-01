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

def func(points: list) -> float:
    size = len(points)
    res = 0
    p1 = 0
    for i in range(1, size - 1):
        res += abs(ccw(points[i], points[(i + 1) % size], points[p1])) * 0.5
    return res

N = int(input())
l = [list(map(int, input().split())) for i in range(N)]
convex_hull = grahamScan(l)
print(int(func(convex_hull) // 50))