from sys import stdin
w=stdin.readline().rstrip()
l=[]
for i in range(len(w)):
    l.append(w[i:])
l.sort()
print('\n'.join(l))
