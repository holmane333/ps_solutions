#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m;
int ary[100002], min_seg_tree[1000002], max_seg_tree[1000002];

void max_init(int node, int start, int end) {
	if (start == end) {
		max_seg_tree[node] = ary[start];
	}
	else {
		max_init(node * 2, start, (start + end) / 2);
		max_init(node * 2 + 1, (start + end) / 2 + 1, end);
		max_seg_tree[node] = max(max_seg_tree[node * 2], max_seg_tree[node * 2 + 1]);
	}
}

void min_init(int node, int start, int end) {
	if (start == end) {
		min_seg_tree[node] = ary[start];
	}
	else {
		min_init(node * 2, start, (start + end) / 2);
		min_init(node * 2 + 1, (start + end) / 2 + 1, end);
		min_seg_tree[node] = min(min_seg_tree[node * 2], min_seg_tree[node * 2 + 1]);
	}
}

int min_find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && end <= right) return min_seg_tree[node];
	int a = min_find(node * 2, start, (start + end) / 2, left, right);
	int b = min_find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return min(a, b);
}

int max_find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return max_seg_tree[node];
	int a = max_find(node * 2, start, (start + end) / 2, left, right);
	int b = max_find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return max(a, b);
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
	}
	max_init(1, 1, n);
	min_init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", min_find(1, 1, n, a, b), max_find(1, 1, n, a, b));
	
	}
	
	
	return 0;
}
