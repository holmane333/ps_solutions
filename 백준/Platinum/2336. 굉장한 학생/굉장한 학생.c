#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

typedef struct pair {
	int a, b, c;
}pair;

int n;
pair ary[1000010];
int seg_tree[2000010];

int compare(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.a == b.a) {
		if (a.b == b.b) return a.c - b.c;
		return a.b - b.b;
	}
	return a.a - b.a;
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx < start || idx > end) return;
	if (start == end) {
		seg_tree[node] = diff;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
	seg_tree[node] = min(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}

int find(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return 1e9;
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) / 2;
	int a = find(node * 2, start, mid, left, right);
	int b = find(node * 2 + 1, mid + 1, end, left, right);
	return min(a, b);
}

int main(void) {
	scanf("%d", &n);
	int t;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t); ary[t].a = i;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t); ary[t].b = i;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t); ary[t].c = i;
	}
	qsort(ary + 1, n, sizeof(pair), compare);
	int res = 0;
	for (int i = 1; i < 2000010; ++i) seg_tree[i] = 1e9;
	for (int i = 1; i <= n; ++i) {
		int data1 = ary[i].b, data2 = ary[i].c;
		int mindata = find(1, 1, n, 1, data1);
		update(1, 1, n, data1, data2);
		if (data2 < mindata) ++res;
		//printf("%d %d %d\n", ary[i].a, ary[i].b, ary[i].c);
	}
	printf("%d\n", res);
	
	return 0;
}
