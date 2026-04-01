#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m;
int ary[2000002], seg_tree[4000002];

int static compare (const void* first, const void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = 1;
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg_tree[node] = seg_tree[node] + diff;
	if (start == end) return;
	if (index <= (start + end) / 2) update(node * 2, start, (start + end) / 2, index, diff);
	else update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
}

int kth(int node, int start, int end, int count) {
	if (start == end) return start;
	if (count <= seg_tree[node * 2]) return kth(node * 2, start, (start + end) / 2, count);
	return kth(node * 2 + 1, (start + end) / 2 + 1, end, count - seg_tree[node * 2]);
}

int main(void) {
	scanf("%d", &n);
	int data;
	for (int i = 1; i <= n; i++) scanf("%d", &ary[i]);
	qsort(ary, n + 1, sizeof(int), compare);
	int q[100010];
	init(1, 1, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &q[i]);
		q[i]++;
	}
	int res[100001];
	for (int i = n; i > 0; i--) {
		int k = kth(1, 1, n, q[i]);
		update(1, 1, n, k, -1LL);
		res[i] = ary[k];
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}
