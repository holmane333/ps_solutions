from sys import stdin
a,b,c=map(int,stdin.readline().rstrip().split())
def ai(a,b,c):
    if b==0:
        return 1
    ret=ai(a,b//2,c)%c
    if b%2==0:
        return ret*ret%c
    else:
        return (ret*ret%c)*a%c


print(ai(a,b,c))
