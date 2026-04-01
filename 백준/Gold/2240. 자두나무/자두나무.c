#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, a[1010], dp[1010][40][3];

int DP(int t, int w, int p) {
	if (t > n) return 0;
	if (dp[t][w][p] != -1) return dp[t][w][p];
	if (w <= 0) dp[t][w][p] = DP(t + 1, w, p) + (a[t] == p);
	else dp[t][w][p] = max(DP(t + 1, w - 1, !p) + (a[t] == !p), DP(t + 1, w, p) + (a[t] == p));
	return dp[t][w][p];
}

int main(void) {
	int w;
	scanf("%d %d", &n, &w);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		--a[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", DP(1, w, 0));
	return 0;
}
