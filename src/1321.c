#include <stdio.h>
#pragma warning(disable:4996)

int n;
int ary[2000021], seg_tree[2097154 * 2];

int init(int node, int start, int end) {
	if (start == end) return seg_tree[node] = ary[start];
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
	for (int i = 1; i <= n; i++) scanf("%d", &ary[i]);
	init(1, 1, n);
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d", &b, &c);
			update(1, 1, n, b, c);
		}
		else {
			scanf("%d", &b);
			printf("%d\n", kth(1, 1, n, b));
		}
	}
	return 0;
}
