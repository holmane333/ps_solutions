#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, k;
long long ary[1000002], seg_tree[2097154], min_seg_tree[2097154];

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

void min_init(int node, int start, int end) {
	if (start == end) {
		min_seg_tree[node] = start;
	}
	else {
		min_init(node * 2, start, (start + end) / 2);
		min_init(node * 2 + 1, (start + end) / 2 + 1, end);
		if (ary[min_seg_tree[node * 2]] > ary[min_seg_tree[node * 2 + 1]]) min_seg_tree[node] = min_seg_tree[node * 2 + 1];
		else min_seg_tree[node] = min_seg_tree[node * 2];
	}
}

int find(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && end <= right) return min_seg_tree[node];
	int a = find(node * 2, start, (start + end) / 2, left, right);
	int b = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (a == INT_MAX && b == INT_MAX) return a;
	if (a == INT_MAX) return b;
	if (b == INT_MAX) return a;
	if (ary[a] > ary[b]) return b;
	return a;
}

long long solve(int start, int end) {
	int idx = find(1, 1, n, start, end);
	if (start == end) return ary[idx] * ary[idx];
	long long res = ary[idx] * sum(1, 1, n, start, end);
	long long a = 0LL, b = 0LL;
	if (start <= idx - 1) a = solve(start, idx - 1);
	if (end >= idx + 1) b = solve(idx + 1, end);
	res = max(res, max(a, b));
	
	return res;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary[i]);
	}
	init(1, 1, n);
	min_init(1, 1, n);
	
	printf("%lld\n", solve(1, n));
	return 0;
}