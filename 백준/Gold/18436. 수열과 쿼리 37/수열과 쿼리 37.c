#include <stdio.h>
#pragma warning(disable:4996)

int n, m;
int ary[1000002], seg_tree1[2097154], seg_tree2[2097154];

int init1(int node, int start, int end) {
	if (start == end)
		return seg_tree1[node] = !ary[start];
	else {
		int a = init1(node * 2, start, (start + end) / 2);
		int b = init1(node * 2 + 1, (start + end) / 2 + 1, end);
		return seg_tree1[node] = a + b;
	}
}

int init2(int node, int start, int end) {
	if (start == end)
		return seg_tree2[node] = ary[start];
	else {
		int a = init2(node * 2, start, (start + end) / 2);
		int b = init2(node * 2 + 1, (start + end) / 2 + 1, end);
		return seg_tree2[node] = a + b;
	}
}

void update1(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	if (start == end) {
		seg_tree1[node] = diff;
		return;
	}
	update1(node * 2, start, (start + end) / 2, index, diff);
	update1(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	seg_tree1[node] = seg_tree1[node * 2] + seg_tree1[node * 2 + 1];
}

void update2(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	if (start == end) {
		seg_tree2[node] = diff;
		return;
	}
	update2(node * 2, start, (start + end) / 2, index, diff);
	update2(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	seg_tree2[node] = seg_tree2[node * 2] + seg_tree2[node * 2 + 1];
}

int sum1(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg_tree1[node];
	int a = sum1(node * 2, start, (start + end) / 2, left, right);
	int b = sum1(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return a + b;
}

int sum2(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return seg_tree2[node];
	int a = sum2(node * 2, start, (start + end) / 2, left, right);
	int b = sum2(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return a + b;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
		ary[i] %= 2;
	}
	scanf("%d", &m);
	init1(1, 1, n);
	init2(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c;
			scanf("%d %d", &b, &c);
			c %= 2;
			ary[b] = c;
			update1(1, 1, n, b, !c);
			update2(1, 1, n, b, c);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			if (a == 2) printf("%d\n", sum1(1, 1, n, b, c));
			else printf("%d\n", sum2(1, 1, n, b, c));
		}
	}
	
	
	return 0;
}
