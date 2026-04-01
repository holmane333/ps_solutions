#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, k;
int ary[100010];
ll seg_tree[309715], seg_tree2[309715];

void update(int node, int start, int end, int index, ll diff) {
	if (index < start || index > end) return;
	seg_tree[node] = seg_tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

ll sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return seg_tree[node];
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update2(int node, int start, int end, int index, ll diff) {
	if (index < start || index > end) return;
	seg_tree2[node] = seg_tree2[node] + diff;
	if (start != end) {
		update2(node * 2, start, (start + end) / 2, index, diff);
		update2(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

ll sum2(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return seg_tree2[node];
	return sum2(node * 2, start, (start + end) / 2, left, right) + sum2(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void) {
	scanf("%d", &n);
	int a;
	ll b, cnt = 0LL;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		ary[a + 1] = i;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		b = sum(1, 1, 100000, 1, ary[a + 1] - 1);
		//printf("%d\n", ary[a + 1]);
		cnt += sum2(1, 1, 100000, 1, ary[a + 1] - 1);
		update(1, 1, 100000, ary[a + 1], 1LL);
		update2(1, 1, 100000, ary[a + 1], b);
		//printf("%d %d\n", b, cnt);
	}
	
	if (cnt == 0LL) {
		puts("Attention is what I want");
	}
	else {
		puts("My heart has gone to paradise");
		printf("%lld\n", cnt);
	}
	return 0;
}
