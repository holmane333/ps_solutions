import sys;input=lambda:sys.stdin.readline().rstrip()

N, C = map(int, input().split())
coins = [list(map(int, input().split())) for i in range(N)]
coins.sort(key=lambda x: (x[0]))

res = 0

for i in range(N - 1, -1, -1):
    if (coins[i][0] >= C):
        res += coins[i][1]
        coins.pop()
    else: break

N = len(coins)

while (1):
    tmp = C
    l = [0] * N
    
    for i in range(N - 1, -1, -1):
        val, count = coins[i]
        if (count > 0):
            cnt = min(count, (tmp - 1) // val)
            
            if (cnt > 0):
                l[i] += cnt
                tmp -= cnt * val
    
    if (tmp > 0):
        for i in range(N):
            if coins[i][1] > l[i]:
                val = coins[i][0]
                tmp -= val
                l[i] += 1
                if (tmp <= 0):
                    break
    
    if (tmp > 0):
        break
    
    m = float('inf')
    for i in range(N):
        if (l[i] > 0): m = min(m, coins[i][1] // l[i])
    
    res += m
    for i in range(N):
        if (l[i] > 0): coins[i][1] -= l[i] * m

print(res)