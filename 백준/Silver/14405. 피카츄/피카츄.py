from sys import stdin

count=0
w=stdin.readline().rstrip()
result=[0]
t=0
for i in range(len(w)-1):
    if result[-1]==1 and count>0:
        count-=1
        continue
    if result[-1]==2 and count>0:
        count-=1
        continue
    c=w[i:i+2]
    if c=='pi' or c=='ka':
        result.append(1)
        count=1
    elif c=='ch':
        if i+2<=len(w)-1:
            if w[i+2]=='u':
                result.append(2)
                count=2
            else:
                result.append(0)
        else:
            result.append(0)
    else:
        result.append(0)
if count==0:
    result.append(0)
del result[0]
if 0 in result:
    print('NO')
else:
    print('YES')
