from sys import stdin
l=[]
for i in range(5):
    l.append(list(stdin.readline().rstrip()))
for i in range(15):
    for j in range(5):
        try:
            print(l[j][i],end='')
        except IndexError:
            continue
