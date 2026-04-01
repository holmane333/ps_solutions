#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

typedef struct pair {
	int a, b;
} pair;

int n;
long long seg_tree[400010];
pair sec[100010];

int cmp(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.a == b.a) return a.b - b.b;
	return a.a - b.a;
}

void update(int node, int start, int end, int idx) {
	if (idx < start || end < idx) return;
	++seg_tree[node];
	if (start == end) return;
	int mid = (start + end) / 2;
	update(node << 1, start, mid, idx);
	update((node << 1) + 1, mid + 1, end, idx);
}

long long sum(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 0LL;
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) / 2;
	long long a = sum(node << 1, start, mid, left, right);
	long long b = sum((node << 1) + 1, mid + 1, end, left, right);
	return a + b;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n + n; ++i) {
		int t;
		scanf("%d", &t);
		if (!sec[t].a) sec[t].a = i;
		else sec[t].b = i;
	}
	
	qsort(sec + 1, n, sizeof(pair), cmp);
	long long res = 0LL;
	for (int i = 1; i <= n; ++i) {
		res += sum(1, 1, n + n, sec[i].a, sec[i].b);
		update(1, 1, n + n, sec[i].b);
	}
	printf("%lld\n", res);
	return 0;
}
