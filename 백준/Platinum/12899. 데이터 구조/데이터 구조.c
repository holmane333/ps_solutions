#include <stdio.h>
#pragma warning(disable:4996)

int n = 2000020, m, k;
long long ary[2000021], seg_tree[2097154 * 2];

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg_tree[node] = seg_tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
	}
}

int kth(int node, int start, int end, int count) {
	if (start == end) return start;
	if (count <= seg_tree[node * 2]) return kth(node * 2, start, (start + end) / 2, count);
	return kth(node * 2 + 1, (start + end) / 2 + 1, end, count - seg_tree[node * 2]);
}

int main(void) {
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			update(1, 1, n, b, 1);
		}
		else {
			int k = kth(1, 1, n, b);
			update(1, 1, n, k, -1);
			printf("%d\n", k);
		}
	}
	
	
	return 0;
}
