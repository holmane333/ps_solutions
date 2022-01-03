#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct pair {
	int a, b;
} pair;

int n, m;
long long seg_tree[10001];
pair ary[2000002];

int compare(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.a == b.a) return a.b - b.b;
	return a.a - b.a;
}

void update(int node, int start, int end, int idx) {
	if (idx < start || idx > end) return;
	seg_tree[node]++;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx);
	update(node * 2 + 1, mid + 1, end, idx);
}

long long sum(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0LL;
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) / 2;
	long long a = sum(node * 2, start, mid, left, right);
	long long b = sum(node * 2 + 1, mid + 1, end, left, right);
	return a + b;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &ary[i].a, &ary[i].b);
	}
	qsort(ary + 1, m, sizeof(pair), compare);
	//for (int i = 1; i <= m; ++i) printf("%d %d\n", ary[i].a, ary[i].b);
	long long res = 0LL;
	for (int i = 1; i <= m; ++i) {
		if (ary[i].b + 1 <= n) res += sum(1, 1, n, ary[i].b + 1, n);
		update(1, 1, n, ary[i].b);
	}
	printf("%lld\n", res);
	
	return 0;
}
