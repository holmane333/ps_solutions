a=0
for i in range(5):
    k=int(input())
    if k <= 40:
        k=40
    a+=k
print(a//5)