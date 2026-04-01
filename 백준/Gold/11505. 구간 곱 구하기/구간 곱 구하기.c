#include <stdio.h>
#pragma warning(disable:4996)
#define mod 1000000007

int n, m, k;
long long ary[1000002], seg_tree[2097154];

long long init(int node, int start, int end) {
	if (start == end)
		return seg_tree[node] = ary[start];
	else
		return seg_tree[node] = (init(node * 2, start, (start + end) / 2) * init(node * 2 + 1, (start + end) / 2 + 1, end)) % mod;
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		seg_tree[node] = (seg_tree[node * 2] * seg_tree[node * 2 + 1]) % mod;
	}
	else seg_tree[node] = diff;
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1LL;
	if (left <= start && end <= right) return seg_tree[node];
	return (sum(node * 2, start, (start + end) / 2, left, right) * sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % mod;
}

int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary[i]);
	}
	m += k;
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			update(1, 1, n, b, c);
			ary[b] = c;
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(1, 1, n, b, c));
		}
	}
	return 0;
}