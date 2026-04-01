#include <stdio.h>
#pragma warning(disable:4996)
#define mod 1000000007

long long int dp[5001];

void DP() {
	dp[0] = 1;
	dp[2] = 1;
	
	for (int i = 4; i <= 5000; i += 2) {
		for (int j = 2; j <= i; j++) {
			dp[i] += dp[j - 2] * dp[i - j];
			dp[i] %= mod;
		}
	}
}

int main(void) {
	int tc, data;
	scanf("%d", &tc);
	DP();
	for (int test = 0; test < tc; test++) {
		scanf("%d", &data);
		if (data % 2 == 1) printf("0\n");
		else printf("%lld\n", dp[data]);
	}
	
	return 0;
}
