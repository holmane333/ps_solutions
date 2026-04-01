a=input()
n=0
l_n=[-1,3,6,9,12,15,19,22,26]
l_a=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
for i in range(len(a)):
    k=l_a.index(a[i])
    for j in range(9):
        if l_n[j] < k+1 and l_n[j+1] >= k+1:
            n+=j+3
            break
print(n)