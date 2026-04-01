#include <stdio.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
#define abs(a) ((a) > (0) ? (a) : (-(a)))

int a[100010], s[100010], n, k;
int dp[100010];

int DP(int d) {
	if (dp[d] != -1) return dp[d];
	if (d > n) return 0;
	dp[d] = 1e9;
	for (int i = 1; i < 4; ++i) {
		dp[d] = min(dp[d], DP(d + i) + 1);
	}
	if (s[d] >= k) dp[d] = min(dp[d], DP(d + k) + 1);
	//printf("%d %d %d %d\n", dp[d], d, a[d], s[d]);
	return dp[d];
}

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(dp, -1, sizeof(dp));
	s[n] = 1;
	for (int i = n - 1; i >= 1; --i) {
		if (abs(a[i] - a[i + 1]) == 1) s[i] = s[i + 1] + 1;
		else s[i] = 1;
	}
	
	printf("%d\n", DP(1));
	return 0;
}
