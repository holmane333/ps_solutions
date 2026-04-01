import sys;input=lambda:sys.stdin.readline().rstrip()

res = 0
t = 0
for i in range(20):
    a, b, c = map(str, input().split())
    b = float(b)
    cnt = 0
    match c:
        case 'A+': cnt = 4.5
        case 'A0': cnt = 4.0
        case 'B+': cnt = 3.5
        case 'B0': cnt = 3.0
        case 'C+': cnt = 2.5
        case 'C0': cnt = 2.0
        case 'D+': cnt = 1.5
        case 'D0': cnt = 1.0
        case 'F': cnt = 0.0
        case 'P': continue
    res += b * cnt
    t += b
print(res / t)
