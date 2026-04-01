#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
	int n;
	double a[10010], dp[10010];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &a[i]);
	}
 
	double res = -2e9;
	for (int i = 1; i <= n; ++i) {
		dp[i] = max(dp[i - 1] * a[i], a[i]);
		res = max(res, dp[i]);
	}
 
	printf("%.3lf\n", res);
	return 0;
}