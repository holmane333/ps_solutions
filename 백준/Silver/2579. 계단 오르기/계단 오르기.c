#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, a[310], dp[310];

int DP(int idx) {
	if (idx <= 0) return 0;
	if (idx == 1) return dp[idx] = a[idx];
	if (idx == 2) return dp[idx] = a[idx] + a[idx - 1];
	if (dp[idx] != -1) return dp[idx];
	
	return dp[idx] = max(DP(idx - 2) + a[idx], DP(idx - 3) + a[idx - 1] + a[idx]);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", DP(n));
	return 0;
}
