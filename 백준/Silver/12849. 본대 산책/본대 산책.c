#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

long long int dp[10] = {1, }, dp_cpy[10] = {0, };
long long int mod = 1000000007;

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		memset(dp_cpy, 0, sizeof(dp_cpy));
		dp_cpy[0] = (dp[1] + dp[3]) % mod;
		dp_cpy[1] = (dp[0] + dp[2] + dp[3]) % mod;
		dp_cpy[2] = (dp[1] + dp[3] + dp[4] + dp[5]) % mod;
		dp_cpy[3] = (dp[0] + dp[1] + dp[2] + dp[5]) % mod;
		dp_cpy[4] = (dp[2] + dp[5] + dp[6]) % mod;
		dp_cpy[5] = (dp[3] + dp[2] + dp[4] + dp[7]) % mod;
		dp_cpy[6] = (dp[4] + dp[7]) % mod;
		dp_cpy[7] = (dp[5] + dp[6]) % mod;
		memcpy(dp, dp_cpy, sizeof(dp_cpy));
	}
	
	printf("%lld\n", dp[0]);
	
	return 0;
}
