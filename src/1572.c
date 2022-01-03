#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 100000

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
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary[i]);
		ary[i]++;
	}
	for (int i = 1; i < k; i++) update(1, 1, MAX, ary[i], 1LL);
	
	long long res = 0LL;
	for (int i = k; i <= n; i++) {
		update(1, 1, MAX, ary[i], 1LL);
		int t;
		if (k % 2 == 0) t = kth(1, 1, MAX, k / 2);
		else t = kth(1, 1, MAX, k / 2 + 1);
		res += (long long)t;
		update(1, 1, MAX, ary[i - k + 1], -1LL);
	}
	printf("%lld\n", res - (long long)(n - k + 1));
	
	return 0;
}
