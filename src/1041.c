#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
	int ary[6];
	long long int n;
	scanf("%lld", &n);
	for (int i = 0; i < 6; i++) {
		scanf("%d", &ary[i]);
	}
	if (n == 1LL) {
		int m  = 0;
		for (int i = 1; i < 6; i++) m = ary[m] > ary[i] ? m : i;
		int res = 0;
		for (int i = 0; i < 6; i++) if (m != i) res += ary[i];
		printf("%d\n", res);
	}
	else {
		int sorted[3];
		ary[0] = min(ary[0], ary[5]);
		ary[1] = min(ary[1], ary[4]);
		ary[2] = min(ary[2], ary[3]);
		sorted[0] = min(ary[0], min(ary[1], ary[2]));
		sorted[1] = min(ary[0], max(ary[1], ary[2]));
		sorted[1] = max(sorted[1], min(ary[1], ary[2]));
		sorted[2] = max(ary[0], max(ary[1], ary[2]));
		int three = sorted[0] + sorted[1] + sorted[2];
		int two = sorted[0] + sorted[1];
		int one = sorted[0];
		
		long long int res1 = (n - 1) * (n - 2) * 4 + (n - 2) * (n - 2);
		long long int res2 = (n - 1) * 4 + (n - 2) * 4;
		
		long long int sum = res1 * one + res2 * two + 4 * three;
		
		printf("%lld\n", sum);
	}
	
	
	return 0;
}
