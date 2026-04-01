#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, k;
int c, dp[100001];

int DP(int t) {
	if (t <= 0) return 0;
	if (dp[t] != -1) return dp[t];
	if (dp[t] == -2) return -1;

	for (int i = 1; i < t / 2 + 1; i++) {
		if (DP(i) == -1 || DP(t - i) == -1 || DP(i) == -2 || DP(t - i) == -2) continue;
		dp[t] = dp[t] < DP(i) + DP(t - i) ? dp[t] : DP(i) + DP(t - i);
		if (dp[t] == -1) dp[t] = DP(i) + DP(t - i);
	}
	if (dp[t] == -1) dp[t] = -2;
	return dp[t];
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		dp[c] = 1;
	}
	printf("%d\n", DP(k) != -2 ? DP(k) : -1);
	return 0;
}
