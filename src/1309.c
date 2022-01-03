#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, dp[100001];
	scanf("%d", &n);
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}
	printf("%d\n", dp[n]);


	return 0;
}
