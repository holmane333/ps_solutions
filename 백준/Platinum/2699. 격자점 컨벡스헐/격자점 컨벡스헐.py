import sys;input=lambda:sys.stdin.readline().rstrip()
import math

def ccw(i, j, k):
    area2 = (j[0] - i[0]) * (k[1] - i[1]) - (j[1] - i[1]) * (k[0] - i[0])
    if (area2 < 0): return True
    return False

def grahamScan(points):
    idx = 0
    point = [(points[i][0], points[i][1]) for i in range(len(points))]
    for i in range(1, len(point)):
        if (point[i][1] > point[idx][1]):
            idx = i
        elif (point[i][1] == point[idx][1] and point[i][0] < point[idx][0]):
            idx = i
    res = [point[idx]]
    point.pop(idx)

    for i in range(len(point)):
        dy, dx = point[i][1] - res[0][1], point[i][0] - res[0][0]
        point[i] = (point[i][0], point[i][1], math.atan2(dy, dx), dx * dx + dy * dy)
    point.sort(key = lambda p: (-p[2], p[3]))
    for i in range(len(point)):
        while (len(res) >= 2):
            if (not ccw(res[-2], res[-1], point[i])):
                res.pop()
            else:
                break
        res.append((point[i][0], point[i][1]))

    return res

for tc in range(int(input())):
    N = int(input())
    coords = []
    while len(coords) < N * 2:
        coords.extend(map(int, sys.stdin.readline().split()))
    
    l = []
    for i in range(0, len(coords), 2):
        l.append([coords[i], coords[i+1]])
    # assert(not (N == 25 and l[0][0] == 2 and l[0][1] == 1))
    result = grahamScan(l)
    print(len(result))
    for p in result:
        print(f"{p[0]} {p[1]}")