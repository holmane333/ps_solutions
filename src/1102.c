#include <stdio.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, res;
int dp[1 << 17], ary[20][20];

int DP(int k, int bit) {
	if (k >= res) return 0;
	if (dp[bit] != -1) return dp[bit];
	dp[bit] = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (!(bit & (1 << i))) continue;
		for (int j = 0; j < n; j++) {
 			if (!(bit & (1 << j)))
 				dp[bit] = min(dp[bit], DP(k + 1, bit | (1 << j)) + ary[i][j]);
		}
	}
	return dp[bit];
}

int main(void) {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &ary[i][j]);
		}
	}
	char str[20];
	int str_bit = 0, cnt = 0;
	scanf("%s", str);
	for (int i = 0; i < n; i++) {
		if (str[i] == 'Y') {
			str_bit |= (1 << i);
			cnt++;
		}
	}
	scanf("%d", &res);
	if (res == 0) printf("0\n");
	else if (cnt == 0) printf("-1\n");
	else printf("%d\n", DP(cnt, str_bit));
	return 0;
}
