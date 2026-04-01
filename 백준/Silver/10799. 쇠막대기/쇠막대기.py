from sys import stdin
l=0
count=0
w=stdin.readline().rstrip()
for i in range(len(w)):
    if w[i]=='(':
        if w[i+1]=='(':
            l+=1
        else:
            count+=l
    else:
        if w[i-1]=='(':
            continue
        else:
            l-=1
            count+=1
print(count)
