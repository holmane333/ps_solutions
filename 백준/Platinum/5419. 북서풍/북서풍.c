#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

typedef struct pair {
	int a, b;
}pair;

int n;
pair ary[200010];
long long seg_tree[2000010];

long long nC2(long long a) {
	return a * (a - 1) / 2;
}

int compare1(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.b == b.b) return a.a - b.a;
	return a.b - b.b;
}

int compare2(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.a == b.a) return a.b - b.b;
	return b.a - a.a;
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
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(seg_tree, 0, sizeof(seg_tree));
		memset(ary, 0, sizeof(ary));
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d", &(ary[i].a), &(ary[i].b));
		}
		qsort(ary + 1, n, sizeof(pair), compare1);
		for (int i = 1, t = 0, prev = 1e9; i <= n; ++i) {
			if (prev != ary[i].b) {
				++t;
				prev = ary[i].b;
			}
			ary[i].b = t;
		}
		qsort(ary + 1, n, sizeof(pair), compare2);
		long long res = 0LL;
		for (int i = 1; i <= n; ++i) {
			int data = ary[i].b;
			res += sum(1, 1, n, 1, data);
			update(1, 1, n, data);
			//printf("%d %d %lld\n", ary[i].a, ary[i].b, res);
		}
		printf("%lld\n", res);
	}
	
	return 0;
}
