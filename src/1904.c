#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int dp[1000001];

int DP(int n) {
	if (n <= 0) return 0;
	if (dp[n] != -1) return dp[n];
	dp[n] = (DP(n - 1) + DP(n - 2))%15746;
	return dp[n];
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	dp[1] = 1;
	dp[2] = 2;
	scanf("%d", &n);
	printf("%d\n", DP(n));
	
	return 0;
}