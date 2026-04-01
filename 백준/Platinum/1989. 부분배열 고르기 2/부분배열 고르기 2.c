#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m, lidx = 1, ridx = 1;
long long ary[100002], ary2[100002], seg_tree[1000002];
long long sec[100002], ans;

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

void solve(int start, int end) {
	int idx = find(1, 1, n, start, end);
	if (idx == INT_MAX) return;
	if (start == end) {
		long long res = ary2[start] * ary2[start];
		if (ans < res) {
			ans = res;
			lidx = start;
			ridx = start;
		}
		return;
	}
	long long res = ary2[idx] * (sec[end] - sec[start - 1]);
	if (start <= idx - 1) solve(start, idx - 1);
	if (end >= idx + 1) solve(idx + 1, end);
	if (ans < res) {
		ans = res;
		lidx = start;
		ridx = end;
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary2[i]);
		ary[i] = i;
		sec[i] = sec[i - 1] + ary2[i];
	}
	init(1, 1, n);
	solve(1, n);
	printf("%lld\n", ans);
	printf("%d %d\n", lidx, ridx);
	
	return 0;
}
