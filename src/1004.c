#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <memory.h>

int main() {
	int i, testcase, result[50][2];
	scanf("%d", &testcase);
	memset(result, -1, sizeof(result));
	for (i = 0; i < testcase; i++) {
		long long int x1, y1, x2, y2;
		int n,j;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			long long int c1, c2, r;
			scanf("%lld %lld %lld", &c1, &c2, &r);
			long long int d1 = pow(x1 - c1, 2) + pow(y1 - c2, 2);
			long long int d2 = pow(x2 - c1, 2) + pow(y2 - c2, 2);
			if (d1 > pow(r,2)) result[j][0] = 0;
			else result[j][0] = 1;
			if (d2 > pow(r,2)) result[j][1] = 0;
			else result[j][1] = 1;
		}
		int res = 0;
		for (j = 0; j < n; j++) {
			if (result[j][0] != result[j][1]) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}