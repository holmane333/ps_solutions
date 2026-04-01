#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int ary[200002], seg_tree[2000002];

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = ary[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx < start || idx > end) return;
	if (start == end) {
		seg_tree[node] += diff;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

int sum(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) 	return seg_tree[node];
	int mid = (start + end) / 2;
	int a = sum(node * 2, start, mid, left, right);
	int b = sum(node * 2 + 1, mid + 1, end, left, right);
	return a + b;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ary[i]);
		ary[i] += 1;
	}
	int ary1[200001], ary2[200001];
	for (int i = 1; i <= n; ++i) {
		ary1[i] = sum(1, 1, n + 1, ary[i] + 1, n + 1);
		update(1, 1, n + 1, ary[i], 1);
	}
	memset(seg_tree, 0, sizeof(seg_tree));
	for (int i = n; i >= 1; --i) {
		ary2[i] = sum(1, 1, n + 1, 1, ary[i] - 1);
		update(1, 1, n + 1, ary[i], 1);
	}
	long long res = 0LL;
	for (int i = 1; i <= n; ++i) res += (long long)ary1[i] * (long long)ary2[i];
	printf("%lld\n", res);
	return 0;
}
