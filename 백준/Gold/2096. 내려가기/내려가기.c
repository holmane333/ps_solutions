#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int dp[2][5], pre_dp[2][5];
int n;

int main(void) {
	scanf("%d", &n);
	int a, b, c;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (dp[0][1] == -1) {
			dp[0][1] = a;
			dp[0][2] = b;
			dp[0][3] = c;
			dp[1][1] = a;
			dp[1][2] = b;
			dp[1][3] = c;
		}
		else {
			for (int j = 1; j <= 3; j++) {
				if (j - 1 <= 0) {
					dp[1][j] = max(pre_dp[1][1], pre_dp[1][2]) + a;
				}
				else if (j + 1 > 3) {
					dp[1][j] = max(pre_dp[1][2], pre_dp[1][3]) + c;
				}
				else {
					dp[1][j] = max(max(pre_dp[1][1], pre_dp[1][2]), pre_dp[1][3]) + b;
				}
			}
			for (int j = 1; j <= 3; j++) {
				if (j - 1 <= 0) {
					dp[0][j] = min(pre_dp[0][1], pre_dp[0][2]) + a;
				}
				else if (j + 1 > 3) {
					dp[0][j] = min(pre_dp[0][2], pre_dp[0][3]) + c;
				}
				else {
					dp[0][j] = min(min(pre_dp[0][1], pre_dp[0][2]), pre_dp[0][3]) + b;
				}
			}
		}
		for (int j = 1; j <= 3; j++) {
			pre_dp[0][j] = dp[0][j];
			pre_dp[1][j] = dp[1][j];
		}
	}
	
	printf("%d %d\n", max(max(dp[1][1], dp[1][2]), dp[1][3]), min(min(dp[0][1], dp[0][2]), dp[0][3]));
	return 0;
}
