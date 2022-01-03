#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m;
long long ary[100002], ary2[100002], seg_tree[1000002];

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = start;
	}
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		if (ary2[seg_tree[node * 2]] <= ary2[seg_tree[node * 2 + 1]]) seg_tree[node] = seg_tree[node * 2];
		else seg_tree[node] = seg_tree[node * 2 + 1];
	}
}


int find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && end <= right) return seg_tree[node];
	int a = find(node * 2, start, (start + end) / 2, left, right);
	int b = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (a == INT_MAX && b == INT_MAX) return a;
	if (a == INT_MAX) return b;
	if (b == INT_MAX) return a;
	if (ary2[a] > ary2[b]) return b;
	else return a;
}

long long solve(int start, int end) {
	int idx = find(1, 1, n, start, end);
	if (start == end) return ary2[idx];
	long long res = ary2[idx] * (end - start + 1), a = 0LL, b = 0LL;
	if (start <= idx - 1) a = solve(start, idx - 1);
	if (end >= idx + 1) b = solve(idx + 1, end);
	res = max(res, max(a, b));
	return res;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary2[i]);
		ary[i] = i;
	}
	init(1, 1, n);
	printf("%lld\n", solve(1, n));
	
	
	return 0;
}
