from sys import stdin

MAX = 1000010
n = int(stdin.readline())
l = list(map(int, stdin.readline().split()))
l.insert(0, 0)
seg_tree = [0 for _ in range(1000010)]
m = int(stdin.readline())
q1 = []
q2 = []

def init(node, start, end):
	if (start == end):
		seg_tree[node] = l[start]
		return
	mid = (start + end) // 2
	init(node * 2, start, mid)
	init(node * 2 + 1, mid + 1, end)
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1]

def update(node, start, end, index, diff):
	if (index < start or index > end):
		return
	if (start == end):
		seg_tree[node] = diff;
		return
	mid = (start + end) // 2
	update(node * 2, start, mid, index, diff)
	update(node * 2 + 1, mid + 1, end, index, diff)
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1]

def find(node, start, end, left, right):
	if (right < start or left > end):
		return 0
	if (start == end):
		return seg_tree[node]
	if (left <= start and end <= right):
		return seg_tree[node]
	mid = (start + end) // 2
	a = find(node * 2, start, mid, left, right)
	b = find(node * 2 + 1, mid + 1, end, left, right)
	return a + b

for i in range(m):
	inp = list(map(int, stdin.readline().split()))
	if (inp[0] == 1):
		q1.append(inp)
	else:
		q2.append([inp, len(q2)])

q2.sort(key = lambda x : x[0])

init(1, 1, n)
listlen = len(q1)
qlen = len(q2)
res = ["0" for _ in range(qlen)]
idx = 0

for i in range(listlen):
	while(idx < qlen and q2[idx][0][1] <= i):
		res[q2[idx][1]] = str(find(1, 1, n, q2[idx][0][2], q2[idx][0][3]))
		idx += 1
	update(1, 1, n, q1[i][1], q1[i][2])

while (idx < qlen):
	res[q2[idx][1]] = str(find(1, 1, n, q2[idx][0][2], q2[idx][0][3]))
	idx += 1

print('\n'.join(res))