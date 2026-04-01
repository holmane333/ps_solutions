a=input()
t='abcdefghijklmnopqrstuvwxyz'
b=[]
for i in range(26):
    if t[i] in a:
        b.append(str(a.find(t[i])))
    else:
        b.append('-1')
print(' '.join(b))