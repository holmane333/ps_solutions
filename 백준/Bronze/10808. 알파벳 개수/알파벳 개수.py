from sys import stdin
w=stdin.readline().rstrip()
l=[0 for i in range(26)]
for i in w:
    l[ord(i)-97]+=1
for i in range(len(l)):
    if i!=len(l)-1:
        print(l[i],end=' ')
    else:
        print(l[i])
