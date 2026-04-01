from sys import stdin
from itertools import permutations

n=int(stdin.readline().rstrip())
l=list(stdin.readline().rstrip().split())
l1=[]
l2=[]
for i in range(n+1):
    l1.append(i)
    l2.append(9-i)

result=[]
for i in permutations(l2):
    c=0
    for j in range(n):
        if l[j]=="<":
            if i[j] > i[j+1]:
                c=1
                break
        if l[j]==">":
            if i[j] < i[j+1]:
                c=1
                break
    if c==0:
        for j in range(n+1):
            print(i[j],end='')
        break
print()
for i in permutations(l1):
    c=0
    for j in range(n):
        if l[j]=="<":
            if i[j] > i[j+1]:
                c=1
                break
        if l[j]==">":
            if i[j] < i[j+1]:
                c=1
                break
    if c==0:
        for j in range(n+1):
            print(i[j],end='')
        break
