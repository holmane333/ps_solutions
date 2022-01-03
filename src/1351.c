#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 10000000

long long int n, p, q;
long long int dp[MAX + 1];

long long int DP(long long int t) {
	if (t <= MAX) return dp[t];
	return DP(t / p) + DP(t / q);
}

int main(void) {
	scanf("%lld %lld %lld", &n, &p, &q);
	dp[0] = 1;
	for (int i = 1; i <= MAX; i++) dp[i] = dp[i / p] + dp[i / q];
	
	printf("%lld\n", DP(n));
	
	return 0;
}
