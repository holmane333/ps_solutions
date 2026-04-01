#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

long long int dp[1000];

long long int DP(int n) {
	if (n <= 0) return 0;
	if (dp[n] != -1) return dp[n];
	dp[n] = DP(n - 1) + 1;
	for (int i = 3;; i++) {
		if (n - i <= 0) break;
		dp[n] = dp[n] > DP(n - i) * (i - 1) ? dp[n] : DP(n - i) * (i - 1);
	}
	return dp[n];
}

int main() {
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= 6; i++) {
		dp[i] = i;
	}

	printf("%lld\n", DP(n));

	return 0;
}
