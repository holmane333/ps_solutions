import sys;input=lambda:sys.stdin.readline().rstrip()
import math
from decimal import Decimal, ROUND_HALF_UP

def ccw(i, j, k):
    area2 = (j[0] - i[0]) * (k[1] - i[1]) - (j[1] - i[1]) * (k[0] - i[0])
    if (area2 > 0): return 1
    elif (area2 < 0): return -1
    return 0

def grahamScan(points: list) -> list:
    idx = 0
    point = sorted(points, key=lambda x:(x[0], x[1]))
    res = [tuple(point[idx])]
    point.pop(idx)

    for i in range(len(point)):
        dy, dx = point[i][1] - res[0][1], point[i][0] - res[0][0]
        point[i] = (point[i][0], point[i][1], math.atan2(dy, dx), dx * dx + dy * dy)
    point.sort(key = lambda p: (p[2], p[3]))
    for i in range(len(point)):
        res.append((point[i][0], point[i][1]))
    pos = len(res) - 1
    for i in range(pos, 0, -1):
        if (ccw(res[0], res[pos], res[pos - 1]) == 0): pos -= 1
        else: break
    res = res[:pos] + list(reversed(res[pos:]))
    return res

def dist(p1: list, p2: list) -> Decimal:
    return Decimal.sqrt(Decimal((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])))

N = int(input())
l = [list(map(str, input().split())) for i in range(N)]
l = [[int(i[0]), int(i[1])] for i in l if i[2] == 'Y']
arr = grahamScan(l)
print(len(arr))
arr = [f'{i[0]} {i[1]}' for i in arr]
print('\n'.join(arr))