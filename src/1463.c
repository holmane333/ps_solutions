#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int dp[1000001];

int min(int a, int b) {
	return a < b ? a : b;
}

int DP(int n) {
	if (n <= 1) return 0;
	if (dp[n] != -1) return dp[n];
	if (n / 2 == 0) {
		dp[n] = DP(n - 1) + 1;
	}
	else if (n / 3 == 0) {
		dp[n] = min(DP(n - 1) + 1, DP(n / 2) + 1);
	}
	else {
		if ((n % 2 == 0) && (n % 3 == 0)) dp[n] = min(DP(n - 1) + 1, min(DP(n / 2) + 1, DP(n / 3) + 1));
		else if (n % 2 == 0) dp[n] = min(DP(n - 1) + 1, DP(n / 2) + 1);
		else if (n % 3 == 0) dp[n] = min(DP(n - 1) + 1, DP(n / 3) + 1);
		else dp[n] = DP(n - 1) + 1;
	}
	return dp[n];
}

int main() {
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	printf("%d\n", DP(n));

	return 0;
}