from sys import stdin
n=stdin.readline().rstrip()
k=int('{}'.format(n),8)
l=bin(k)[2:]
print(l)
