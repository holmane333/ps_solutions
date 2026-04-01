from sys import stdin

n,a=map(int,stdin.readline().split())
l=list(map(int,stdin.readline().split()))
l.sort()
while True:
    if l==[]:
        break
    elif l[0]<=a:
        del l[0]
        a+=1
    else:
        break
print(a)
