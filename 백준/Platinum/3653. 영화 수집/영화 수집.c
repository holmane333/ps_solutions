#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, m, k;
long long ary[1000002], seg_tree[2097154];

long long init(int node, int start, int end) {
	if (start == end)
		return seg_tree[node] = ary[start];
	else
		return seg_tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg_tree[node] = seg_tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return seg_tree[node];
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		scanf("%d %d", &n, &m);
		memset(ary, 0, sizeof(ary));
		memset(seg_tree, 0, sizeof(seg_tree));
		for (int i = 1; i <= n; i++) ary[i + m] = 1;
		init(1, 1, n + m);
		memset(ary, 0, sizeof(ary));
		for (int i = 1; i <= n; i++) ary[i] = m + i;
		for (int i = m; i > 0; i--) {
			int a;
			scanf("%d", &a);
			printf("%lld\n", sum(1, 1, n + m, 1, ary[a] - 1));
			update(1, 1, n + m, ary[a], -1LL);
			update(1, 1, n + m, i, 1LL);
			ary[a] = i;
		}
		
	}
	return 0;
}
