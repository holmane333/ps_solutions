#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long
#define mod 1000000000

ll dp[1000010];

int main(void) {
	ll n;
	scanf("%lld", &n);
	dp[0] = 0LL;
	dp[1] = 0LL;
	dp[2] = 1LL;
	for (int i = 3; i <= n; ++i) dp[i] = ((dp[i - 1] + dp[i - 2]) * (i - 1)) % mod;
	printf("%lld\n", dp[n]);
	return 0;
}
