import sys;input=lambda:sys.stdin.readline().rstrip()
import math

def ccw(i, j, k):
    area2 = (j[0] - i[0]) * (k[1] - i[1]) - (j[1] - i[1]) * (k[0] - i[0])
    if (area2 > 0): return True
    return False

def grahamScan(points):
    idx = 0
    point = [(points[i][0], points[i][1]) for i in range(len(points))]
    for i in range(1, len(point)):
        if (point[idx][1] > point[i][1]):
            idx = i
        elif (point[idx][1] == point[i][1] and point[idx][0] < point[i][0]):
            idx = i
    res = [point[idx]]
    point.pop(idx)

    for i in range(len(point)):
        dy, dx = point[i][1] - res[0][1], point[i][0] - res[0][0]
        point[i] = (point[i][0], point[i][1], math.atan2(dy, dx), dx * dx + dy * dy)
    point.sort(key = lambda p: (p[2], p[3]))
    for i in range(len(point)):
        while (len(res) >= 2):
            if (not ccw(res[-2], res[-1], point[i])):
                res.pop()
            else:
                break
        res.append((point[i][0], point[i][1]))

    return res

N = int(input())
l = [list(map(int, input().split())) for i in range(N)]
print(len(grahamScan(l)))