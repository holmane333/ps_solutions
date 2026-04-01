#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, m, c, dp[20][20];
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= m; j++) {
			if (i == 1) dp[i][j] = 1;
			else {
				cnt += dp[i - 1][j];
				dp[i][j] = cnt;
			}
		}
	}
	if (c == 0) {
		printf("%d\n", dp[n][m]);
	}
	else {
		int k = 1;
		while (c > m) {
			c -= m;
			k++;
		}
		printf("%d\n", dp[k][c] * dp[n - k + 1][m - c + 1]);
	}



	return 0;
}
