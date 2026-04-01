#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, h, m;
int ary[4587530], seg_tree_min[16777226], seg_tree_max[16777226], lazy[16777226];

void rangeupdate(int node, int start, int end, int left, int right, int diff) {
	if (lazy[node] != 0) {
		seg_tree_min[node] += lazy[node];
		seg_tree_max[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		else ary[start] += lazy[node];
		lazy[node] = 0;
	}
	if (right < start || left > end) return;
	else if (left <= start && end <= right) {
		seg_tree_min[node] += diff;
		seg_tree_max[node] += diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		else ary[start] += diff;
	}
	else {
		rangeupdate(node * 2, start, (start + end) / 2, left, right, diff);
		rangeupdate(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
		seg_tree_min[node] = min(seg_tree_min[node * 2], seg_tree_min[node * 2 + 1]);
		seg_tree_max[node] = max(seg_tree_max[node * 2], seg_tree_max[node * 2 + 1]);
	}
}

int find_low(int node, int start, int end, int left, int right) {
	if (lazy[node] != 0) {
		seg_tree_min[node] += lazy[node];
		seg_tree_max[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		else ary[start] += lazy[node];
		lazy[node] = 0;
	}
	if (left > end || right < start) return 1e9;
	if (left <= start && end <= right) return seg_tree_min[node];
	int a = find_low(node * 2, start, (start + end) / 2, left, right);
	int b = find_low(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	seg_tree_min[node] = min(seg_tree_min[node * 2], seg_tree_min[node * 2 + 1]);
	seg_tree_max[node] = max(seg_tree_max[node * 2], seg_tree_max[node * 2 + 1]);
	return min(a, b);
}

int find_high(int node, int start, int end, int left, int right) {
	if (lazy[node] != 0) {
		seg_tree_min[node] += lazy[node];
		seg_tree_max[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		else ary[start] += lazy[node];
		lazy[node] = 0;
	}
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg_tree_max[node];
	int a = find_high(node * 2, start, (start + end) / 2, left, right);
	int b = find_high(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	seg_tree_min[node] = min(seg_tree_min[node * 2], seg_tree_min[node * 2 + 1]);
	seg_tree_max[node] = max(seg_tree_max[node * 2], seg_tree_max[node * 2 + 1]);
	return max(a, b);
}

int find(int node, int start, int end, int idx) {
	if (lazy[node] != 0) {
		seg_tree_min[node] += lazy[node];
		seg_tree_max[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		else ary[start] += lazy[node];
		lazy[node] = 0;
	}
	if (idx > end || start > idx) return 0;
	if (start == end) return ary[start];
	int a = find(node * 2, start, (start + end) / 2, idx);
	int b = find(node * 2 + 1, (start + end) / 2 + 1, end, idx);
	seg_tree_min[node] = min(seg_tree_min[node * 2], seg_tree_min[node * 2 + 1]);
	seg_tree_max[node] = max(seg_tree_max[node * 2], seg_tree_max[node * 2 + 1]);
	return a + b;
}

int main(void) {
	scanf("%d %d %d", &n, &h, &m);
	for (int i = 0; i < m; i++) {
		char a[200];
		scanf("%s", a);
		if (!strcmp(a, "state")) {
			int b;
			scanf("%d", &b);
			++b;
			printf("%d\n", find(1, 1, n, b));
			continue;
		}
		int b, c, d;
		if (!strcmp(a, "groupchange")) scanf("%d %d %d", &b, &c, &d);
		else {
			scanf("%d %d", &b, &d);
			c = b;
		}
		++b;
		++c;
		//printf("%d %d\n", b, c);
		if (d >= 0) {
			int t = min(d, h - find_high(1, 1, n, b, c));
			rangeupdate(1, 1, n, b, c, t);
			printf("%d\n", t);
		}
		else {
			int t = max(d, -find_low(1, 1, n, b, c));
			rangeupdate(1, 1, n, b, c, t);
			printf("%d\n", t);
		}
	}
	
	return 0;
}
