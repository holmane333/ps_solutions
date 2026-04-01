from sys import stdin
l=list()
for i in range(9):
    l.append(int(stdin.readline()))
k=max(l)
print('%d\n%d'%(k,l.index(k)+1))
