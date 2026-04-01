#include <stdio.h>
#include <memory.h>
#pragma warning (disable:4996)
#define ll long long
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m;
ll dp[220][110], k;

ll DP(int n, int r) {
	if (n == r || r == 0) return 1LL;
	if (dp[n][r] != -1) return dp[n][r];
	dp[n][r] = DP(n - 1, r) + DP(n - 1, r - 1);
	dp[n][r] = min(dp[n][r], 1e9);
	return dp[n][r];
}

int main(void) {
	scanf("%d %d %lld", &n, &m, &k);
	memset(dp, -1, sizeof(dp));
	
	if (DP(n + m, n) < k) printf("-1\n");
	else {
		while (n > 0 || m > 0) {
			ll temp = DP(n + m - 1, n - 1);
			//printf("%d %d %lld\n", n, m, temp);
			if (n > 0 && k <= temp) {
				printf("a");
				--n;
			}
			else {
				printf("z");
				--m;
				k -= temp;
			}
		}
		puts("");
	}
	
	return 0;
}
