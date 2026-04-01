import sys;input=lambda:sys.stdin.readline().rstrip()
import math

def ccw(i, j, k):
    area2 = (j[0] - i[0]) * (k[1] - i[1]) - (j[1] - i[1]) * (k[0] - i[0])
    if (area2 > 0): return 1
    elif (area2 < 0): return -1
    return 0

def grahamScan(points):
    idx = 0
    point = [(points[i][0], points[i][1], i) for i in range(len(points))]
    for i in range(1, len(point)):
        if (point[idx][1] > point[i][1] or point[idx][1] == point[i][1] and point[idx][0] < point[i][0]): idx = i
    res = [point[idx]]
    point.pop(idx)
    for i in range(len(point)):
        dy, dx = point[i][1] - res[0][1], point[i][0] - res[0][0]
        point[i] = (point[i][0], point[i][1], int(1e9 * math.atan2(dy, dx)), dx * dx + dy * dy, point[i][2])
    point.sort(key = lambda p: (p[2], p[3]))
    for i in range(len(point)):
        res.append((point[i][0], point[i][1], point[i][4]))
    pos = len(res) - 1
    for i in range(pos, 0, -1):
        if (ccw(res[0], res[pos], res[pos - 1]) == 0): pos -= 1
        else: break
    res = res[:pos] + list(reversed(res[pos:]))
    return res

TC = int(input())
for tc in range(TC):
    s = list(map(int, input().split()))
    N = s[0]
    l = []
    for i in range(1, N + 1):
        l.append((s[i * 2 - 1], s[i * 2]))
    print(*[i[2] for i in grahamScan(l)], end='')
    if (tc != TC - 1): print()