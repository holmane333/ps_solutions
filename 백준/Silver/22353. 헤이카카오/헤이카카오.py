a, d_, k_ = map(int, input().split())

d = d_ / 100
k = k_ / 100

o = 0
c = 1
p = 1
while d <= 1:
    o += p * d * c
    
    p *= 1 - d
    d += d * k
    c += 1


o += p * c

print('%.7f' %(o * a))