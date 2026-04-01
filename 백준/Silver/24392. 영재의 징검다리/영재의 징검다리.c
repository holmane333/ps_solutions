#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long
#define mod 1000000007

int n, m;
int map[1010][1010];
ll dp[1010][1010];

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		dp[n][i] = (ll)map[n][i];
	}
	
	for (int i = n - 1; i >= 1; --i) {
		for (int j = 1; j <= m; ++j) {
			if (map[i][j])
				dp[i][j] = (dp[i + 1][j - 1] + dp[i + 1][j] + dp[i + 1][j + 1]) % mod;
		}
	}
	
	ll res = 0LL;
	for (int i = 1; i <= m; ++i) {
		res += dp[1][i];
		res %= mod;
	}
	
	printf("%lld\n", res);
	return 0;
}
