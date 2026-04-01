#include <stdio.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, k;
int check[102];
int dp[102][102];

int DP(int i, int cnt, int coupon) {
	if (i > n) return cnt;
	if (dp[i][coupon]) return dp[i][coupon] + cnt;
	if (check[i]) return DP(i + 1, cnt, coupon);
	
	int ans = INT_MAX;
	ans = min(ans, DP(i + 1, cnt + 10000, coupon));
	ans = min(ans, DP(i + 3, cnt + 25000, coupon + 1));
	ans = min(ans, DP(i + 5, cnt + 37000, coupon + 2));
	
	if (coupon >= 3) {
		ans = min(ans, DP(i + 1, cnt, coupon - 3));
	}
	
	dp[i][coupon] = ans - cnt;
	return ans;
}

int main() {
	scanf("%d %d", &n, &k);
	int c;
	for (int i = 0; i < k; i++) {
		scanf("%d", &c);
		check[c] = 1;
	}
	printf("%d\n", DP(1, 0, 0));
	
	return 0;
}
