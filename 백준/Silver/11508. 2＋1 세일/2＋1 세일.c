#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int cmp(const void* num1, const void* num2) {
	return *(int*)num2 - *(int*)num1;
}

int main(void) {
	int n, ary[100010];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ary[i]);
	}
	qsort(ary + 1, n, sizeof(int), cmp);
	long long res = 0LL;
	for (int i = 1; i <= n; ++i) {
		if (i % 3) res += (long long)ary[i]; 
	}
	printf("%lld\n", res);
	return 0;
}
