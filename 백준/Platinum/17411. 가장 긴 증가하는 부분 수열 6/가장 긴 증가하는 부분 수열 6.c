#include <stdio.h>
#include <stdlib.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct node{
	int key;
	int idx;
}node;

typedef struct pair{
	long long key;
	long long cnt;
}pair;

int n;
node sort_ary[2000002];
int ary[2000002], index[2000002];
pair seg_tree[3000002];

int static compare(const void* first, const void* second) {
    node a = *(node*)first;
    node b = *(node*)second;
    if (a.key == b.key) return a.idx < b.idx;
    return a.key > b.key;
}

int static compare2(const void* first, const void* second) {
    node a = *(node*)first;
    node b = *(node*)second;
    if (a.idx != b.idx) return a.idx > b.idx;
    return a.key > b.key;
}


/*
void init(int node, int start, int end) {
	if (start == end) {
		seg_tree[node] = start;
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg_tree[node] = max(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}*/

void update(int node, int start, int end, int idx, pair diff) {
	if (idx < start || idx > end) return;
	if (start == end) {
		seg_tree[node] = diff;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
	if (seg_tree[node * 2].key > seg_tree[node * 2 + 1].key) {
		seg_tree[node].key = seg_tree[node * 2].key;
		seg_tree[node].cnt = seg_tree[node * 2].cnt;
	}
	else if (seg_tree[node * 2].key < seg_tree[node * 2 + 1].key) {
		seg_tree[node].key = seg_tree[node * 2 + 1].key;
		seg_tree[node].cnt = seg_tree[node * 2 + 1].cnt;
	}
	else {
		seg_tree[node].key = seg_tree[node * 2].key;
		seg_tree[node].cnt = seg_tree[node * 2].cnt + seg_tree[node * 2 + 1].cnt;
	}
}
 
pair find(int node, int start, int end, int left, int right) {
	if (right < start || left > end) {
		pair new1;
		new1.key = 0;
		new1.cnt = 0;
		return new1;
	}
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) / 2;
	pair a = find(node * 2, start, mid, left, right);
	pair b = find(node * 2 + 1, mid + 1, end, left, right);
	if (a.key > b.key) return a;
	else if (a.key < b.key) return b;
	else {
		pair new1;
		new1.key = a.key;
		new1.cnt = a.cnt + b.cnt;
		return new1;
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ary[i]);
		sort_ary[i].key = ary[i];
		sort_ary[i].idx = i;
	}
	//for (int i = 1; i <= n; ++i) printf("%d %d\n", sort_ary[i].key, sort_ary[i].idx);
	qsort(sort_ary + 1, n, sizeof(node), compare);
	//for (int i = 1; i <= n; ++i) printf("%d %d\n", sort_ary[i].key, sort_ary[i].idx);
	for (int i = 1; i <= n; i++) sort_ary[i].key = i;
	qsort(sort_ary + 1, n, sizeof(node), compare2);
	//for (int i = 1; i <= n; i++) sort_ary[i].idx = i;
	//for (int i = 1; i <= n; ++i) printf("%d %d\n", sort_ary[i].key, sort_ary[i].idx);
	pair res;
	res.key = 0;
	res.cnt = 0;
	for (int i = 1; i <= n; ++i) {
		//for (int i = 1; i <= n * 2 + 3; ++i) printf("(%lld, %lld) ", seg_tree[i].key, seg_tree[i].cnt); puts("");
		pair t;
		t.key = 0;
		t.cnt = 1;
		if (sort_ary[i].key - 1 >= 1) t = find(1, 1, n, 1, sort_ary[i].key - 1);
		++(t.key);
		if (t.cnt == 0) ++(t.cnt);
		t.cnt %= 1000000007;
		update(1, 1, n, sort_ary[i].key, t);
		//printf("%d %d %d %d\n", i, res, t, index[i]);
		if (res.key < t.key) {
			res.key = t.key;
			res.cnt = t.cnt;
		}
		else if (res.key == t.key) {
			res.cnt += t.cnt;
		}
		res.cnt %= 1000000007;
		//printf("%lld %lld %lld %lld\n", res.key, res.cnt, t.key, t.cnt);
	}
	//for (int i = 1; i <= n * 2; ++i) printf("(%lld, %lld) ", seg_tree[i].key, seg_tree[i].cnt); puts("");
	printf("%lld %lld\n", res.key, res.cnt);
	return 0;
}