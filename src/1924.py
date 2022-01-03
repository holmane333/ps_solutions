a,b=map(int,input().split())
p=[31,28,31,30,31,30,31,31,30,31,30]
q=['SUN','MON','TUE','WED','THU','FRI','SAT']
n=1
for i in range(0,a-1):
    n+=p[i]
n+=b-1
n%=7
print(q[n])
