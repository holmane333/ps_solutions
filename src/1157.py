a=input()
b='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
c=[]
a=a.upper()
for i in range(26):
    if b[i] in a:
        c.append(a.count(b[i]))
    else:
        c.append(0)
m=max(c)
if c.count(m)==1:
    print(b[c.index(m)])
else:
    print('?')