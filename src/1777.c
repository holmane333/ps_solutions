#include <stdio.h>
#pragma warning(disable:4996)

int n;
int ary[2000021], seg_tree[2097154 * 2];

int init(int node, int start, int end) {
	if (start == end) return seg_tree[node] = 1;
	int a = init(node * 2, start, (start + end) / 2);
	int b = init(node * 2 + 1, (start + end) / 2 + 1, end);
	return seg_tree[node] = a + b;
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
	init(1, 1, n);
	int res[100001], q[100001];
	for (int i = 1; i <= n; i++) {
		int data;
		scanf("%d", &ary[i]);
		ary[i]++;
	}
	for (int i = n; i > 0; i--) {
		int k = kth(1, 1, n, ary[i]);
		update(1, 1, n, k, -1LL);
		res[k] = i;
	}
	for (int i = n; i > 0; i--) printf("%d ", res[i]);
	puts("");
	return 0;
}
