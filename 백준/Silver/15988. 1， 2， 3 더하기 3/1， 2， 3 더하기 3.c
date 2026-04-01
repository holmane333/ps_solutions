#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)
#define ll long long
#define min(x, y) ((x) > (y) ? (y) : (x))
#define mod 1000000009

ll dp[1000001];

ll DP(ll n) {
	if (n <= 0LL) return 0LL;
	if (dp[n] != -1LL) return dp[n];
	dp[n] = (DP(n - 1) + DP(n - 2) + DP(n - 3)) % mod;
	return dp[n];
}

int main() {
	int testcase;
    ll n;
	scanf("%d", &testcase);
	memset(dp, -1, sizeof(dp));
	dp[1] = 1LL;
	dp[2] = 2LL;
	dp[3] = 4LL;
	for (int i = 0; i < testcase; i++) {
		scanf("%lld", &n);
		printf("%lld\n", DP(n));
	}

	return 0;
}