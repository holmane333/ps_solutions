#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int dp[1000001];
int data[1000001];
int min(int a, int b) {
	return a < b ? a : b;
}

int DP(int n) {
	if (n <= 0) return 0;
	if (dp[n] != -1) return dp[n];
	if ((DP(n - 1) < 0) || (DP(n - 1) + data[n] < 0)) dp[n] = data[n];
	else dp[n] = DP(n - 1) + data[n];
	return dp[n];
}

int main() {
	int n,max=-1001;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}
	memset(dp, -1, sizeof(dp));
	dp[1] = data[1];
	DP(n);
	for (int i = 1; i <= n; i++) {
		if (max < dp[i]) max = dp[i];
	}

	printf("%d\n", max);
	return 0;
}