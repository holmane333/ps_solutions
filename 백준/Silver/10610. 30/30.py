from sys import stdin


n=int(stdin.readline().rstrip())


w=str(n)
l=[]
if n%3!=0 or '0' not in w:
    print(-1)
else:
    l=list(w)
    l.sort(reverse=True)
    print(''.join(l))
