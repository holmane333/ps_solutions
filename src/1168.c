#include <stdio.h>
#pragma warning(disable:4996)

int n, k;
long long ary[2000021], seg_tree[2097154 * 2];

int init(int node, int start, int end) {
	if (start == end) return seg_tree[node] = 1;
	return seg_tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
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
	scanf("%d %d", &n, &k);
	int cnt = 1;
	init(1, 1, n);
	printf("<");
	for (int i = 0; i < n; i++) {
		int s = n - i;
		cnt += k - 1;
		if (cnt % s == 0) cnt = s;
		else cnt %= s;
		int k = kth(1, 1, n, cnt);
		update(1, 1, n, k, -1LL);
		if (i == n - 1) printf("%d", k);
		else printf("%d, ", k);
	}
	printf(">\n");
	
	return 0;
}
