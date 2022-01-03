#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int i, testcase;
	scanf("%d", &testcase);
	for (i = 0; i < testcase; i++) {
		long long int x1, y1, r1, x2, y2, r2;
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);
		long long int d = pow(x1-x2, 2)+pow(y1-y2,2);
		if ((x1 == x2) && (y1 == y2) && (r1 != r2)) {
			puts("0");
			continue;
		}
		if ((x1 == x2) && (y1 == y2) && (r1 == r2) && (r1 == 0)) {
			puts("1");
			continue;
		}
		if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
			puts("-1");
			continue;
		}
		if ((d ==pow( r1 + r2,2)) || (d == pow(r2-r1,2)) || (d == pow(r1-r2,2))) {
			puts("1");
		}
		else if ((d > pow(r1 + r2,2)) || (d  < pow(r2-r1,2)) || (d  < pow(r1-r2,2))) {
			puts("0");
		}
		else {
			puts("2");
		}
	}
}
