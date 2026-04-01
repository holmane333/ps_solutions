#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m;
int ary[2000002], seg_tree[4000002];

void update(int node, int start, int end, int index, int diff) {
	if (index < start || index > end) return;
	if (start == end) {
		seg_tree[node] = diff;
		return;
	}
	update(node * 2, start, (start + end) / 2, index, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

int sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg_tree[node];
	int a = sum(node * 2, start, (start + end) / 2, left, right);
	int b = sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return a + b;
}

int main(void) {
	scanf("%d", &n);
	int data;
	long long res = 0LL;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &data);
		res += (long long)sum(1, 1, n + 1, data + 1, n + 1);
		update(1, 1, n + 1, data, 1);
	}
	printf("%lld\n", res);
	
	return 0;
}
