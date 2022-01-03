from sys import stdin

a,b,c=map(int,stdin.readline().split())
e,s,m=1,1,1
count=1
while True:
    if (a==e) and (b==s) and (c==m):
        break
    else:
        e+=1
        s+=1
        m+=1
        if e>15:
            e=1
        if s>28:
            s=1
        if m>19:
            m=1
        count+=1
print(count)
