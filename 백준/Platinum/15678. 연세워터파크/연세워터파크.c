#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, l;
long long ary[100002], seg_tree[1000002];

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

void update(int node, int start, int end, int idx, long long diff) {
	if (start > idx || end < idx) return;
	if (start == end) {
		seg_tree[node] = diff;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
	seg_tree[node] = max(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}


long long find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return LLONG_MIN;
	if (left <= start && end <= right) return seg_tree[node];
	long long a = find(node * 2, start, (start + end) / 2, left, right);
	long long b = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return max(a, b);
}

int main(void) {
	scanf("%d %d", &n, &l);
	for (int i = n; i >= 1; --i) {
		scanf("%lld", &ary[i]);
	}
	for (int i = 1; i < 1000001; ++i) seg_tree[i] = LLONG_MIN;
	update(1, 1, n, 1, ary[1]);
	long long res = ary[1];
	//for (int i = n; i >= 1; --i) printf("%lld ", ary[i]); puts("");
	for (int i = 2; i <= n; ++i) {
		long long a = find(1, 1, n, max(1, i - l), i - 1);
		long long b = ary[i] + max(a, 0LL);
		update(1, 1, n, i, b);
		//printf("%lld %lld %lld %lld %d %d\n", res, a, b, ary[i], max(1, i - l), i - 1);
		res = max(res, b);
	}
	
	printf("%lld\n", res);
	return 0;
}
