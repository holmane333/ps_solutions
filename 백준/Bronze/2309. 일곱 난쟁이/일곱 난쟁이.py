from sys import stdin

l=[]
for i in range(9):
    l.append(int(stdin.readline().rstrip()))
for i in range(9):
    k=l.pop(i)
    for j in range(8):
        count=0
        t=l.pop(j)
        for m in range(7):
            count+=l[m]
        if count==100:
            break
        l.insert(j,t)
    if count==100:
        break
    l.insert(i,k)
l.sort()
for i in range(7):
    print(l[i])
