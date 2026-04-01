testcase=int(input())
for i in range(testcase):
    a=str(input())
    l=[]
    for j in range(len(a)):
        l.append(1)
    r=0
    if a[0]=='O':
        l[0]=1
    else:
        l[0]=0
    for j in range(1,len(a)):
        if a[j]=='O':
            l[j]=l[j-1]+1
        else:
            l[j]=0
    for j in range(len(a)):
        r+=l[j]
    print(r)