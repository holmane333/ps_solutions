from sys import stdin
n=int(stdin.readline().rstrip())
l=list(map(int,stdin.readline().rstrip().split()))
r_l=sorted(l)
result=[]
for i in range(n):
    result.append(str(r_l.index(l[i])))
    r_l[r_l.index(l[i])]='a'
print(' '.join(result))