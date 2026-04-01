from sys import stdin
import math

xm, vx, vy, xa, va, tk = map(int, stdin.readline().split())

x, y = xm + vx * tk, vy * tk - 16 * tk * tk
dis = math.sqrt((xa - x) * (xa - x) + y * y)

tt = tk - dis / va
a = math.atan2(y, x - xa) * 180 / math.pi
if (0 <= tt and y >= 0 and 0 < a < 180):
    print(tt, a)
else:
    print("start running")