from sys import stdin
w,h=map(int,stdin.readline().rstrip().split())
x,y=map(int,stdin.readline().rstrip().split())
t=int(stdin.readline().rstrip())
x+=t
y+=t
x1=x%w
y1=y%h
x=x//w
y=y//h
if x%2!=0:
    x1=w-x1
if y%2!=0:
    y1=h-y1
print(x1,y1)
