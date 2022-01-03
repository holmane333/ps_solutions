#include <stdio.h>
#pragma warning(disable:4996)

typedef struct node{
	long long data, lazy;
}node;

int n, m, k;
long long ary[1000002];
node seg_tree[2097154];

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg_tree[node].data = seg_tree[node].data + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

void rangeupdate(int node, int start, int end, int left, int right, long long diff) {
	if (seg_tree[node].lazy != 0) {
		seg_tree[node].data = (end - start + 1 - seg_tree[node].data);
		if (start != end) {
			seg_tree[node * 2].lazy = !seg_tree[node * 2].lazy;
			seg_tree[node * 2 + 1].lazy = !seg_tree[node * 2 + 1].lazy;
		}
		seg_tree[node].lazy = 0;
	}
	if (right < start || left > end) return;
	else if (left <= start && end <= right) {
		seg_tree[node].data = (end - start + 1 - seg_tree[node].data);
		if (start != end) {
			seg_tree[node * 2].lazy = !seg_tree[node * 2].lazy;
			seg_tree[node * 2 + 1].lazy = !seg_tree[node * 2 + 1].lazy;
		}
	}
	else {
		rangeupdate(node * 2, start, (start + end) / 2, left, right, diff);
		rangeupdate(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
		seg_tree[node].data = seg_tree[node * 2].data + seg_tree[node * 2 + 1].data;
	}
}
 
long long sum(int node, int start, int end, int left, int right) {
	if (seg_tree[node].lazy != 0) {
		seg_tree[node].data = (end - start + 1 - seg_tree[node].data);
		if (start != end) {
			seg_tree[node * 2].lazy = !seg_tree[node * 2].lazy;
			seg_tree[node * 2 + 1].lazy = !seg_tree[node * 2 + 1].lazy;
		}
		seg_tree[node].lazy = 0;
	}
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return seg_tree[node].data;
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			rangeupdate(1, 1, n, b, c, 1LL);
		}
		else {
			printf("%lld\n", sum(1, 1, n, b, c));
		}
	}
	
	
	return 0;
}
