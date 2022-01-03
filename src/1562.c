#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define mod 1000000000

int n;
long long int dp[100][10][(1 << 10) + 1];

long long int DP(int len, int num, int cnt) {
	if (len == n) return (1 << 10) - 1 == cnt ? 1 : 0;
	if (dp[len][num][cnt] != -1) return dp[len][num][cnt];
	
	dp[len][num][cnt] = 0;
	if(num - 1 >= 0)
		dp[len][num][cnt] += DP(len + 1, num - 1, cnt | 1 << (num - 1));
	if(num + 1 < 10)
		dp[len][num][cnt] += DP(len + 1, num + 1, cnt | 1 << (num + 1));
	
	dp[len][num][cnt] %= mod;
	return dp[len][num][cnt];
}

int main() {
	scanf("%d", &n);
	long long int res = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 10; i++) {
		res += DP(1, i, 1 << i);
		res %= mod;
	}
	printf("%lld\n", res);
	
	return 0;
}