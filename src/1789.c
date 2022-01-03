#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

long long int dp[100001];

long long int DP(int n) {
	if (dp[n] != -1) return dp[n];
	dp[n] = DP(n - 1) + n;
	return dp[n];
}

int main() {
	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	long long int n, i;
	scanf("%lld", &n);
	for (i = 0;; i++) {
		if (n - DP(i) <= i) break;
	}
	printf("%lld\n", i);
	return 0;
}