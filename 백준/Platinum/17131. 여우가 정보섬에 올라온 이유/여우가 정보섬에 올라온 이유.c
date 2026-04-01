#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MOD 1000000007
#define MAX 400001
typedef struct pair{
	int a, b;
}pair;

int n;
pair ary[1000001];
int seg_tree[2000001];

int compare(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	if (a.b == b.b) return a.a - b.a;
	return a.b - b.b;
}

void update(int node, int start, int end, int idx) {
	if (idx < start || idx > end) return;
	seg_tree[node]++;
	if (start == end) return;
	int mid = (start + end) >> 1;
	update(node * 2, start, mid, idx);
	update(node * 2 + 1, mid + 1, end, idx);
}

int sum(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) >> 1;
	int a = sum(node * 2, start, mid, left, right);
	int b = sum(node * 2 + 1, mid + 1, end, left, right);
	return a + b;
}



int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &ary[i].a, &ary[i].b);
		ary[i].a += 200001;
		ary[i].b += 200001;
	}
	qsort(ary + 1, n, sizeof(pair), compare);
	//for (int i = 1; i <= n; ++i) printf("%d %d\n", ary[i].a, ary[i].b);
	int i = n;
	long long res = 0LL;
	while (i >= 1) {
		//printf("%d\n", i);
		int stack[1000001], top = 0;
		int a = ary[i].a;
		int b = ary[i].b;
		stack[top++] = a;
		--i;
		while(i >= 1) {
			if (b != ary[i].b) break;
			stack[top++] = ary[i].a;
			--i;
		}
		for (int j = 0; j < top; ++j) {
			//if (stack[j] != 1 && stack[j] != MAX) printf("%lld %lld\n", (long long)sum(1, 1, MAX, 1, stack[j] - 1), (long long)sum(1, 1, MAX, stack[j] + 1, MAX));
			if (stack[j] != 1 && stack[j] != MAX) res = (res + (long long)sum(1, 1, MAX, 1, stack[j] - 1) * (long long)sum(1, 1, MAX, stack[j] + 1, MAX)) % MOD;
		}
		//for (int j = 0; j < top; ++j) printf("%d ", stack[j]); puts("");
		for (int j = 0; j < top; ++j) {
			update(1, 1, MAX, stack[j]);
		}
	}
	printf("%lld\n", res);
	return 0;
}
