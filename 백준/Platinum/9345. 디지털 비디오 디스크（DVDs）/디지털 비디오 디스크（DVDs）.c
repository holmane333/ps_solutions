#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int n, m, k;
long long ary[1000002], max_seg_tree[2097154], min_seg_tree[2097154];

long long max_init(int node, int start, int end) {
	if (start == end)
		return max_seg_tree[node] = ary[start];
	else {
		max_init(node * 2, start, (start + end) / 2);
		max_init(node * 2 + 1, (start + end) / 2 + 1, end);
		return max_seg_tree[node] = max(max_seg_tree[node * 2], max_seg_tree[node * 2 + 1]);
	}
}

long long min_init(int node, int start, int end) {
	if (start == end)
		return min_seg_tree[node] = ary[start];
	else {
		min_init(node * 2, start, (start + end) / 2);
		min_init(node * 2 + 1, (start + end) / 2 + 1, end);
		return min_seg_tree[node] = min(min_seg_tree[node * 2], min_seg_tree[node * 2 + 1]);
	}
}

void max_update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	if (start == end) max_seg_tree[node] = diff;
	else {
		max_update(node * 2, start, (start + end) / 2, index, diff);
		max_update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		max_seg_tree[node] = max(max_seg_tree[node * 2], max_seg_tree[node * 2 + 1]);
	}
}

void min_update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	if (start == end) min_seg_tree[node] = diff;
	else {
		min_update(node * 2, start, (start + end) / 2, index, diff);
		min_update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		min_seg_tree[node] = min(min_seg_tree[node * 2], min_seg_tree[node * 2 + 1]);
	}
}


int find_max(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return -1LL;
	if (left <= start && end <= right) return max_seg_tree[node];
	int a = find_max(node * 2, start, (start + end) / 2, left, right);
	int b = find_max(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return max(a, b);
}

int find_min(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && end <= right) return min_seg_tree[node];
	int a = find_min(node * 2, start, (start + end) / 2, left, right);
	int b = find_min(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return min(a, b);
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			ary[i] = i;
		}
		max_init(1, 1, n);
		min_init(1, 1, n);
		for (int i = 0; i < m; i++) {
			int a, b, c, t;
			scanf("%d %d %d", &a, &b, &c);
			b++; c++;
			if (a == 0) {
				min_update(1, 1, n, b, ary[c]);
				min_update(1, 1, n, c, ary[b]);
				max_update(1, 1, n, b, ary[c]);
				max_update(1, 1, n, c, ary[b]);
				swap(ary[b], ary[c], t);
			}
			else {
				int maxans = find_max(1, 1, n, b, c);
				int minans = find_min(1, 1, n, b, c);
				if (maxans == c && minans == b) printf("YES\n");
				else printf("NO\n");
			}
		}
		
	}
	return 0;
}
