#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n;
int seg_tree[10010];
int ary[100], count[2010], num[2010];

int cmp(const void* num1, const void* num2) {
	return *(int*)num1 - *(int*)num2;
}

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = count[start] ? start : 1e9;
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg_tree[node] = min(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}

void update(int node, int start, int end, int idx) {
	if (idx < start || idx > end) return;
	if (start == end) {
		seg_tree[node] = 1e9;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx);
	update(node * 2 + 1, mid + 1, end, idx);
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
	for (int i = 1; i <= 1010; ++i) seg_tree[i] = 1e9;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ary[i]);
		++ary[i];
		++count[ary[i]];
		++num[ary[i]];
	}
	qsort(ary + 1, n, sizeof(int), cmp);
	init(1, 1, 1010);
	int i = 1;
	while (i <= n) {
		int t = ary[i];
		if (num[t] == 0) {
			i += count[t];
			continue;
		}
		if (!num[t + 1]) {
			for (int j = 0; j < num[t]; ++j) printf("%d ", t - 1);
			num[t] = 0;
			i += count[t];
			//printf("a ");
		}
		else {
			int k = find(1, 1, 1010, t + 2, 1010);
			if (k == 1e9) {
				for (int j = 0; j < num[t + 1]; ++j) printf("%d ", t + 1 - 1);
				for (int j = 0; j < num[t]; ++j) printf("%d ", t - 1);
				num[t] = num[t + 1] = 0;
				i += count[t] + count[t + 1];
			//printf("b ");
			}
			else {
				for (int j = 0; j < num[t]; ++j) printf("%d ", t - 1);
				printf("%d ", k - 1);
				if (--num[k] == 0) update(1, 1, 1010, k);
				i += count[t];
			//printf("c ");
			}
		}
	}
	puts("");
	return 0;
}
