#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct pair {
	int a, b;
} pair;

int cmp(const void* num1, const void* num2) {
	pair a = *(pair*)num1;
	pair b = *(pair*)num2;
	
	if (a.a == b.a) return a.b - b.b;
	return a.a - b.a;
}

int main(void) {
	int n;
	pair ary[2000020];
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i += 2) {
		int a, b;
		scanf("%d %d", &a, &b);
		ary[i].a = a;
		ary[i].b = 1;
		ary[i + 1].a = b;
		ary[i + 1].b = -1;
	}
	qsort(ary, 2 * n, sizeof(pair), cmp);
	
	int mres = 0, res = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (ary[i].b == 1) res += 1;
		else res -= 1;
		mres = max(mres, res);
	}
	
	printf("%d\n", mres);
	return 0;
}
