from sys import stdin
w=stdin.readline()
result=[]
for j in w:
    t=ord(j)
    if 65<=t<=90:
        if t-64<=13:
            result.append('%c'%(t+13))
        else:
            result.append('%c'%(t-13))
    elif 97<=t<=122:
        if t-96<=13:
            result.append('%c'%(t+13))
        else:
            result.append('%c'%(t-13))
    else:
        result.append(j)
print(''.join(result))

