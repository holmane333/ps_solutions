testcase=int(input())
count=0
for _ in range(testcase):
    s=0
    l=[]
    w=input()
    for i in w:
        if i not in l:
            l.append(i)
            s+=1
        else:
            if l[-1]!=i:
                break
            else:
                s+=1
    if s==len(w):
        count+=1
print(count)
