#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
typedef struct node{
	int key;
	int idx;
}node;

int compare(const void *num1, const void *num2) {
    int a = (*(node*)num1).key;
    int b = (*(node*)num2).key;
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

int n;
node ary[200002];
int seg_tree[300002];

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = 1;
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx < start || idx > end) return;
	if (start == end) {
		seg_tree[node] += diff;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
	seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

int sum(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) / 2;
	int a = sum(node * 2, start, mid, left, right);
	int b = sum(node * 2 + 1, mid + 1, end, left, right);
	return a + b;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &(ary[i].key));
		ary[i].idx = i;
	}
	qsort(ary + 1, n, sizeof(node), compare);
	init(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		if (i % 2) {
			int idx = i / 2 + 1;
			printf("%d\n", sum(1, 1, n, 1, ary[idx].idx) - 1);
			update(1, 1, n, ary[idx].idx, -1);
		}
		else {
			int idx = n - i / 2 + 1;
			printf("%d\n", sum(1, 1, n, ary[idx].idx, n) - 1);
			update(1, 1, n, ary[idx].idx, -1);
		}
	}
	
	return 0;
}
