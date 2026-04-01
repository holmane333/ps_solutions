#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, k;
long long ary[1000002], min_seg_tree[2097154];

void min_update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	if (start != end) {
		min_update(node * 2, start, (start + end) / 2, index, diff);
		min_update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		if (ary[min_seg_tree[node * 2]] > ary[min_seg_tree[node * 2 + 1]]) min_seg_tree[node] = min_seg_tree[node * 2 + 1];
		else min_seg_tree[node] = min_seg_tree[node * 2];
	}
}

void min_init(int node, int start, int end) {
	if (start == end) {
		min_seg_tree[node] = start;
	}
	else {
		min_init(node * 2, start, (start + end) / 2);
		min_init(node * 2 + 1, (start + end) / 2 + 1, end);
		if (ary[min_seg_tree[node * 2]] > ary[min_seg_tree[node * 2 + 1]]) min_seg_tree[node] = min_seg_tree[node * 2 + 1];
		else min_seg_tree[node] = min_seg_tree[node * 2];
	}
}

int find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return min_seg_tree[node];
	int a = find(node * 2, start, (start + end) / 2, left, right);
	int b = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (a == -1 && b == -1) return a;
	if (a == -1) return b;
	if (b == -1) return a;
	if (ary[a] > ary[b]) return b;
	return a;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary[i]);
	}
	min_init(1, 1, n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			long long diff = c - ary[b];
			ary[b] = c;
			min_update(1, 1, n, b, c);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%d\n", find(1, 1, n, b, c));
		}
	}
	return 0;
}