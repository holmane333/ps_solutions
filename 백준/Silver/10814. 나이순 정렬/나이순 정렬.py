from sys import stdin
t=int(stdin.readline().rstrip())
l=[]
for i in range(t):
    a,b=map(str,stdin.readline().rstrip().split())
    l.append([int(a),b])
l.sort(key=lambda x:x[0])
for i in range(len(l)):
    print('%d %s'%(l[i][0],l[i][1]))
