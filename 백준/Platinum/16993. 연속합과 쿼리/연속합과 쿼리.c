#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct pair {
	int all, val, lval, rval;
} pair;

int n, ary[100010];
pair seg_tree[400010];

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node].all = ary[start];
		seg_tree[node].val = ary[start];
		seg_tree[node].lval = ary[start];
		seg_tree[node].rval = ary[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg_tree[node].all = seg_tree[node * 2].all + seg_tree[node * 2 + 1].all;
	seg_tree[node].lval = max(seg_tree[node * 2].lval, seg_tree[node * 2].all + seg_tree[node * 2 + 1].lval);
	seg_tree[node].rval = max(seg_tree[node * 2 + 1].rval, seg_tree[node * 2 + 1].all + seg_tree[node * 2].rval);
	seg_tree[node].val = max(max(seg_tree[node * 2].val, seg_tree[node * 2 + 1].val), seg_tree[node * 2].rval + seg_tree[node * 2 + 1].lval);
}

pair findmax(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		pair new1 = {0, -1e9, -1e9, -1e9};
		return new1;
	}
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) / 2;
	pair lval = findmax(node * 2, start, mid, left, right), rval = findmax(node * 2 + 1, mid + 1, end, left, right);
	pair new1;
	new1.all = lval.all + rval.all;
	new1.lval = max(lval.lval, lval.all + rval.lval);
	new1.rval = max(rval.rval, rval.all + lval.rval);
	new1.val = max(max(lval.val, rval.val), lval.rval + rval.lval);
	return new1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &ary[i]);
	init(1, 1, n);
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		pair res = findmax(1, 1, n, x, y);
		printf("%d\n", res.val);
	}
	return 0;
}