#include <stdio.h>
#pragma warning(disable:4996)
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int n, m, k;
long long ary[1000002], seg_tree[2097154];

long long init(int node, int start, int end) {
	if (start == end)
		return seg_tree[node] = ary[start];
	else
		return seg_tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg_tree[node] = seg_tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return seg_tree[node];
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary[i]);
	}
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b, c, t;
		long long d;
		scanf("%d %d %d %lld", &a, &b, &c, &d);
		if (a > b) swap(a, b, t);
		printf("%lld\n", sum(1, 1, n, a, b));
		long long diff = d - ary[c];
		ary[c] = d;
		update(1, 1, n, c, diff);
	}
	
	
	return 0;
}
