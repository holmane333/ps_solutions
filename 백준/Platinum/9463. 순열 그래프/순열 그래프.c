#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, m, k;
int find_ary[1000001];
long long ary[1000002], seg_tree[2097154];

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
		memset(find_ary, 0, sizeof(find_ary));
		memset(ary, 0, sizeof(ary));
		memset(seg_tree, 0, sizeof(seg_tree));
		
		scanf("%d", &n);
		long long res = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &ary[i]);
			find_ary[ary[i]] = i;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &ary[i]);
			ary[i] = find_ary[ary[i]];
		}
		for (int i = 1; i <= n; i++){
			res += sum(1, 1, n, ary[i] + 1, n);
			update(1, 1, n, ary[i], 1LL);
		}
		printf("%lld\n", res);
	}
	return 0;
}
