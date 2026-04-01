#include <stdio.h>
#include <stdlib.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct node{
	int key;
	int idx;
}node;

typedef struct pair {
	int a, b;
} pair;

int n;
node sort_ary[2000002];
pair ary[2000002];
int seg_tree[3000002];

int static compare(const void* first, const void* second) {
    int a = (*(node*)first).idx;
    int b = (*(node*)second).idx;
    return a > b;
}

void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = start;
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg_tree[node] = max(seg_tree[node * 2], seg_tree[node * 2 + 1]);
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
	seg_tree[node] = max(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}
 
int find(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) / 2;
	int a = find(node * 2, start, mid, left, right);
	int b = find(node * 2 + 1, mid + 1, end, left, right);
	if (a > b) return a;
	return b;
}
 
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &ary[i].a, &ary[i].b);
		sort_ary[i].key = ary[i].b;
		sort_ary[i].idx = ary[i].a;
	}
	qsort(sort_ary + 1, n, sizeof(node), compare);
	//for (int i = 1; i <= n; ++i) printf("%d ", index[i]); puts("");
	//for (int i = 1; i <= n; ++i) printf("%d %d\n", sort_ary[i].idx, sort_ary[i].key);
	int res = 0, res_ary[2000002] = { 0, };
	int idx = 1;
	for (int i = 1; i <= n; ++i) {
		//for (int i = 1; i <= n * 2; ++i) printf("%d ", seg_tree[i]); puts("");
		int t;
		if (sort_ary[i].key - 1 <= 0) t = 0;
		else t = find(1, 1, 500001, 1, sort_ary[i].key - 1);
		++t;
		update(1, 1, 500001, sort_ary[i].key, t);
		//printf("%d %d %d %d\n", i, res, t, index[i]);
		if (res <= t) {
			res = t;
			idx = i;
		}
		res_ary[i] = t;
	}
	int ans[2000002] = { 0, }, k = n - res;
	printf("%d\n", k);
	ans[res--] = sort_ary[idx].idx;
	//for (int i = 1; i <= n; ++i) printf("%d ", res_ary[i]); puts("");
	//printf("%d\n", idx);
	for (int i = idx - 1; i >= 1; --i) {
		if (res_ary[i] == res) {
			ans[res--] = sort_ary[i].idx;
		}
		if (res == 0) break;
	}
	int index = 1;
	for (int i = 1; i <= n; ++i) {
		if (sort_ary[i].idx == ans[index]) ++index;
		else printf("%d\n", sort_ary[i].idx);
	}
	
	return 0;
}