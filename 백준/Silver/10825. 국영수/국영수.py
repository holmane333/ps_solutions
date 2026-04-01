from sys import stdin
t=int(stdin.readline().rstrip())
l=[]
for i in range(t):
    a,b,c,d=map(str,stdin.readline().rstrip().split())
    l.append([a,int(b),int(c),int(d)])
l.sort()
l.sort(key=lambda x:x[3],reverse=True)
l.sort(key=lambda x:x[2])
l.sort(key=lambda x:x[1],reverse=True)
for i in range(len(l)):
    print('%s'%l[i][0])
