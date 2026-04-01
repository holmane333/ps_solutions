#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m;
int ary[100002], seg_tree[1000002];

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = ary[start];
	}
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		seg_tree[node] = min(seg_tree[node * 2], seg_tree[node * 2 + 1]);
	}
}


int find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && end <= right) return seg_tree[node];
	int a = find(node * 2, start, (start + end) / 2, left, right);
	int b = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return min(a, b);
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
	}
	for (int i = 1; i < 1000001; i++) seg_tree[i] = INT_MAX;
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", find(1, 1, n, a, b));
		
	}
	
	
	return 0;
}
