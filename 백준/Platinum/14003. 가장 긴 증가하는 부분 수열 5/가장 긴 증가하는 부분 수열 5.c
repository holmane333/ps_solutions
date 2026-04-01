#include <stdio.h>
#include <stdlib.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct node{
	int key;
	int idx;
}node;

int n;
node sort_ary[2000002];
int ary[2000002], index[2000002], seg_tree[3000002];

int static compare(const void* first, const void* second) {
    int a = (*(node*)first).key;
    int b = (*(node*)second).key;
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
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
		scanf("%d", &ary[i]);
		sort_ary[i].key = ary[i];
		sort_ary[i].idx = i;
	}
	qsort(sort_ary + 1, n, sizeof(node), compare);
	for (int prev = sort_ary[1].key, t = 1, i = 1; i <= n; ++i) {
		if (prev != sort_ary[i].key) ++t;
		index[sort_ary[i].idx] = t;
		prev = sort_ary[i].key;
		//printf("%d\n", t);
	}
	//for (int i = 1; i <= n; ++i) printf("%d ", index[i]); puts("");
	//for (int i = 1; i <= n; ++i) printf("%d %d\n", sort_ary[i].key, sort_ary[i].idx);
	int res = 0, res_ary[2000002] = { 0, };
	int idx = 1;
	for (int i = 1; i <= n; ++i) {
		//for (int i = 1; i <= n * 2; ++i) printf("%d ", seg_tree[i]); puts("");
		int t;
		if (index[i] - 1 <= 0) t = 0;
		else t = find(1, 1, n, 1, index[i] - 1);
		++t;
		update(1, 1, n, index[i], t);
		//printf("%d %d %d %d\n", i, res, t, index[i]);
		if (res <= t) {
			res = t;
			idx = i;
		}
		res_ary[i] = t;
	}
	printf("%d\n", res);
	int t = 1, ans[2000002] = { 0, };
	ans[t++] = ary[idx];
	//for (int i = 1; i <= n; ++i) printf("%d ", res_ary[i]); puts("");
	//printf("%d\n", idx);
	for (int i = idx - 1; i >= 1; --i) {
		if (res_ary[i] == res - 1) {
			ans[t++] = ary[i];
			--res;
		}
		if (res == 0) break;
	}
	for (int i = t - 1; i >= 1; --i) printf("%d ", ans[i]); puts("");
	return 0;
}