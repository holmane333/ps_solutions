#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct pair{
	long long data1;
	long long data2;
}pair;

int n, m;
int ary[100002];
pair seg_tree[1000002];

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node].data1 = ary[start];
		seg_tree[node].data2 = 0;
	}
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		seg_tree[node].data1 = max(seg_tree[node * 2].data1, seg_tree[node * 2 + 1].data1);
		seg_tree[node].data2 = max(min(seg_tree[node * 2].data1, seg_tree[node * 2 + 1].data1), max(seg_tree[node * 2].data2, seg_tree[node * 2 + 1].data2));
	}
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx > end || idx < start) return;
	if (start == end) {
		seg_tree[node].data1 = diff;
		seg_tree[node].data2 = 0;
		return;
	}
	update(node * 2, start, (start + end) / 2, idx, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	seg_tree[node].data1 = max(seg_tree[node * 2].data1, seg_tree[node * 2 + 1].data1);
	seg_tree[node].data2 = max(min(seg_tree[node * 2].data1, seg_tree[node * 2 + 1].data1), max(seg_tree[node * 2].data2, seg_tree[node * 2 + 1].data2));
}

pair find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		pair new1;
		new1.data1 = 0LL;
		new1.data2 = 0LL;
		return new1;
	}
	if (left <= start && end <= right) return seg_tree[node];
	pair a = find(node * 2, start, (start + end) / 2, left, right);
	pair b = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	pair new1;
	new1.data1 = max(a.data1, b.data1);
	new1.data2 = max(min(a.data1, b.data1), max(a.data2, b.data2));
	return new1;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
	}
	scanf("%d", &m);
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else {
			pair res = find(1, 1, n, b, c);
			printf("%lld\n", res.data1 + res.data2);
		}
	
	}
	
	
	return 0;
}
