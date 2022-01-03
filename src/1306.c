#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m;
int ary[2000002], seg_tree[4000002];

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = ary[start];
	}
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		seg_tree[node] = max(seg_tree[node * 2], seg_tree[node * 2 + 1]);
	}
}


int find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg_tree[node];
	int a = find(node * 2, start, (start + end) / 2, left, right);
	int b = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return max(a, b);
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
	}
	init(1, 1, n);
	for (int i = m; i <= n - m + 1; i++) {
		printf("%d\n", find(1, 1, n, i - m + 1, i + m - 1));
	}
	
	
	return 0;
}
