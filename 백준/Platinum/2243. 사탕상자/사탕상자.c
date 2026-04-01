#include <stdio.h>
#pragma warning(disable:4996)

int n, k;
long long seg_tree[(1 << 22) + 1]; //2097154 * 2
const int MAX = 1000000;

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg_tree[node] = seg_tree[node] + diff;
	if (start == end) return;
	update(node * 2, start, (start + end) / 2, index, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
}

int kth(int node, int start, int end, int count) {
	if (start == end) return start;
	if (count <= seg_tree[node * 2]) return kth(node * 2, start, (start + end) / 2, count);
	return kth(node * 2 + 1, (start + end) / 2 + 1, end, count - seg_tree[node * 2]);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			scanf("%d", &b);
			int k = kth(1, 1, MAX, b);
			update(1, 1, MAX, k, -1LL);
			printf("%d\n", k);
		}
		else {
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			update(1, 1, MAX, b, c);
		}
	}
	
	return 0;
}
