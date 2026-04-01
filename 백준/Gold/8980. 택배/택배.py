from sys import stdin
n, c=map(int, stdin.readline().rstrip().split())
m = int(stdin.readline().rstrip())
l=[]
for i in range(m):
    l.append(list(map(int,stdin.readline().rstrip().split())))
l.sort(key = lambda x:x[0])
l.sort(key = lambda x:x[1])
t=[0 for i in range(n + 2)]
res = 0
for i in l:
	cnt = 0
	for j in range(i[0], i[1]):
		cnt = max(t[j], cnt)
	Add = min(c - cnt, i[2])
	res += Add
	for j in range(i[0], i[1]):
		t[j] += Add
print(res)