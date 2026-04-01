from sys import stdin
a,b=map(int,stdin.readline().rstrip().split(':'))
a_1,b_1=a,b
while True:
    if b!=0:
        a,b=b,a%b
    else:
        break
print('%d:%d'%(a_1//a,b_1//a))
