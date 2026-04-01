#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, dp[1000001][20];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 20; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 20; j++) {
			if (i >= (1 << j)) dp[i][j] = (dp[i][j - 1] + dp[i - (1 << j)][j]) % 1000000000;
			else dp[i][j] = dp[i][j - 1];
		}
	}
	printf("%d\n", dp[n][19]);
	return 0;
}
