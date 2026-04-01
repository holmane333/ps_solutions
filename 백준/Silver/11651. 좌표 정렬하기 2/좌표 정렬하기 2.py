from sys import stdin
t=int(stdin.readline().rstrip())
l=[]
for i in range(t):
    l.append(list(map(int,stdin.readline().rstrip().split())))
l.sort()
l.sort(key=lambda x:x[1])
for i in range(len(l)):
    print('%d %d'%(l[i][0],l[i][1]))
