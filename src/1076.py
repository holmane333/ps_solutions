from sys import stdin

l=["black","brown","red","orange","yellow","green","blue","violet","grey","white"]

def col(str1):
    for i in range(10):
        if str1==l[i]:
            return i

result=0
str1=stdin.readline().rstrip()
result+=col(str1)
result*=10
str1=stdin.readline().rstrip()
result+=col(str1)
str1=stdin.readline().rstrip()
result*=10**col(str1)

print(result)
