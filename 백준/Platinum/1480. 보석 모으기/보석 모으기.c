#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, c, a[15], dp[11][21][1 << 14];

int DP(int cnt, int cost, int bit) {
	if (cnt == m) return 0;
	if (dp[cnt][cost][bit] != -1) return dp[cnt][cost][bit];
	
	for (int i = 0; i < n; ++i) {
		if (!((1 << i) & bit)) {
			if (cost + a[i] <= c) {
				dp[cnt][cost][bit] = max(dp[cnt][cost][bit], DP(cnt, cost + a[i], bit | (1 << i)) + 1);
			}
		}
	}
	dp[cnt][cost][bit] = max(dp[cnt][cost][bit], DP(cnt + 1, 0, bit));
	dp[cnt][cost][bit] = max(dp[cnt][cost][bit], 0);
	return dp[cnt][cost][bit];
}

int main(void) {
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", DP(0, 0, 0));
	return 0;
}
