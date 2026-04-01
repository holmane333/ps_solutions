import sys;input=lambda:sys.stdin.readline().rstrip()
from decimal import Decimal, getcontext, ROUND_HALF_UP
from functools import cmp_to_key

def ccw(i, j, k):
    area2 = (j[0] - i[0]) * (k[1] - i[1]) - (j[1] - i[1]) * (k[0] - i[0])
    if (area2 > 0): return 1
    elif (area2 < 0): return -1
    return 0

def grahamScan(points: list) -> list:
    idx = 0
    point = sorted(points, key=lambda x:(x[1], x[0]))
    res = [point[idx]]
    point.pop(idx)

    def compare(p1, p2):
        order = ccw(res[0], p1, p2)
        if order == 0:
            d1 = (res[0][0] - p1[0]) ** 2 + (res[0][1] - p1[1]) ** 2
            d2 = (res[0][0] - p2[0]) ** 2 + (res[0][1] - p2[1]) ** 2
            return -1 if d1 < d2 else 1
        return -order
    
    point.sort(key=cmp_to_key(compare))
    for i in range(len(point)):
        while (len(res) >= 2):
            if (ccw(res[-2], res[-1], point[i]) <= 0):
                res.pop()
            else:
                break
        res.append((point[i][0], point[i][1]))
    
    return res

def dist(p1: list, p2: list) -> Decimal:
    return Decimal.sqrt(Decimal((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])))

N, L = map(int, input().split())
l = [list(map(int, input().split())) for i in range(N)]
arr = grahamScan(l)
pi_decimal = Decimal(3.14159265358979323846264338327950288419716939937510)
res = pi_decimal * Decimal(L) * 2

for i in range(1, len(arr)):
    res += dist(arr[i], arr[i - 1])
res += dist(arr[0], arr[-1])
rounded_res = res.quantize(Decimal('1'), rounding=ROUND_HALF_UP)

print(rounded_res)