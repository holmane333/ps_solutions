#include <stdio.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m;
long long ary[1010], ary2[1010], sum[1010], dp[1010][1010][3];

long long DP(int l, int r, int f) {
	if (l <= 1 && r >= n) return 0LL;
	if (dp[l][r][f] != -1) return dp[l][r][f];
	dp[l][r][f] = LLONG_MAX;
	
	int idx = f ? l : r;
	int sum_ary = sum[n] - sum[r] + sum[l - 1];
	
	if (l - 1 >= 1)
		dp[l][r][f] = min(dp[l][r][f], DP(l - 1, r, 1) + sum_ary * (ary2[idx] - ary2[l - 1]));
	
	if (r + 1 <= n)
		dp[l][r][f] = min(dp[l][r][f], DP(l, r + 1, 0) + sum_ary * (ary2[r + 1] - ary2[idx]));
	
	//printf("%d %d %d %lld\n", l, r, f, dp[l][r][f]);
	return dp[l][r][f];
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		ary2[i] = a;
		ary[i] = b;
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + ary[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", DP(m, m, 0));
	
	return 0;
}
