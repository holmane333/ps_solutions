#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, ary[20], ary2[20];

int main(void) {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i) {
		int t;
		scanf("%d", &t);
		++ary[t / 10];
		++ary[t % 10];
	}
	
	ary2[0] = 1;
	for (int i = 1; i <= 10; ++i) {
		ary2[i] = (i - 1) * ary2[i - 2];
	}
	
	long long res = 1;
	for (int i = 0; i <= 9; ++i) {
		res *= (long long)ary2[ary[i]];
	}
	
	printf("%lld\n", res);
	return 0;
}
