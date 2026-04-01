#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct pair {
	long long all, val, lval, rval;
} pair;

typedef struct pair2 {
	int a, i;
} pair2;

int n, ary2[100010][2], ary[3010][3010][2], len[3010];
pair2 aryx[100010], aryy[100010];
pair seg_tree[400010];

const int cmp(const void* num1, const void* num2) {
	return (*(pair2*)num1).a - (*(pair2*)num2).a;
}

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node].all = seg_tree[node].val = seg_tree[node].lval = seg_tree[node].rval = 0;
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx > end || idx < start) return;
	if (start == end) {
		seg_tree[node].all += diff;
		seg_tree[node].lval += diff;
		seg_tree[node].rval += diff;
		seg_tree[node].val += diff;
		return;
	}
	
	int mid = (start + end) >> 1;
	update(node << 1, start, mid, idx, diff);
	update((node << 1) | 1, mid + 1, end, idx, diff);
	
	seg_tree[node].all = seg_tree[node << 1].all + seg_tree[(node << 1) | 1].all;
	seg_tree[node].lval = max(seg_tree[node << 1].lval, seg_tree[node << 1].all + seg_tree[(node << 1) | 1].lval);
	seg_tree[node].rval = max(seg_tree[(node << 1) | 1].rval, seg_tree[(node << 1) | 1].all + seg_tree[node << 1].rval);
	seg_tree[node].val = max(max(seg_tree[node << 1].val, seg_tree[(node << 1) | 1].val), seg_tree[node << 1].rval + seg_tree[(node << 1) | 1].lval);
}

pair findmax(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		pair new1 = {0, -1e9, -1e9, -1e9};
		return new1;
	}
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) >> 1;
	pair lval = findmax(node << 1, start, mid, left, right), rval = findmax((node << 1) | 1, mid + 1, end, left, right);
	pair new1;
	new1.all = lval.all + rval.all;
	new1.lval = max(lval.lval, lval.all + rval.lval);
	new1.rval = max(rval.rval, rval.all + lval.rval);
	new1.val = max(max(lval.val, rval.val), lval.rval + rval.lval);
	return new1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &aryx[i].a, &aryy[i].a, &ary2[i][1]);
		aryx[i].i = aryy[i].i = i;
	}
	//memset(seg_tree, 0, sizeof(seg_tree));
	//init(1, 1, n);
	
	qsort(aryx + 1, n, sizeof(pair2), cmp);
	qsort(aryy + 1, n, sizeof(pair2), cmp);
	
	aryx[0].a = aryy[0].a = -1;
	
	int idx = 0;
	for (int i = 1; i <= n; ++i) {
		if (aryx[i - 1].a != aryx[i].a) ++idx;
		ary2[aryx[i].i][0] = idx;
	}
	
	idx = 0;
	for (int i = 1; i <= n; ++i) {
		if (aryy[i - 1].a != aryy[i].a) ++idx;
		ary[idx][len[idx]][0] = ary2[aryy[i].i][0];
		ary[idx][len[idx]++][1] = ary2[aryy[i].i][1];
	}
	
	long long res = 0LL;
	for (int i = 1; i <= n; ++i) {
		memset(seg_tree, 0, sizeof(seg_tree));
		for (int j = i; j <= n; ++j) {
			for (int k = 0; k < len[j]; ++k) {
				update(1, 1, n, ary[j][k][0], (long long)ary[j][k][1]);
			}
			res = max(res, findmax(1, 1, n, 1, n).val);
		}
	}
	
	printf("%lld\n", res);
	return 0;
}