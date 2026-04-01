#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m;
int ary[100002], seg_tree[1000002];

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = start;
	}
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		if (ary[seg_tree[node * 2]] > ary[seg_tree[node * 2 + 1]]) seg_tree[node] = seg_tree[node * 2 + 1];
		else seg_tree[node] = seg_tree[node * 2];
	}
}

void update(int node, int start, int end, int index) {
	if (index > end || index < start) return;
	if (start == end) {
		seg_tree[node] = index;
		return;
	}
	update(node * 2, start, (start + end) / 2, index);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index);
	if (ary[seg_tree[node * 2]] > ary[seg_tree[node * 2 + 1]]) seg_tree[node] = seg_tree[node * 2 + 1];
	else seg_tree[node] = seg_tree[node * 2];
}

int find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && end <= right) return seg_tree[node];
	int a = find(node * 2, start, (start + end) / 2, left, right);
	int b = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (ary[a] > ary[b]) return b;
	else return a;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
	}
	scanf("%d", &m);
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c;
			scanf("%d %d", &b, &c);
			ary[b] = c;
			update(1, 1, n, b);
		}
		else {
			printf("%d\n", find(1, 1, n, 1, n));
		}
	}
	
	
	return 0;
}
