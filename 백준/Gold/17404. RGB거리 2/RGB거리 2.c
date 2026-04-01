#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int dp[1001][4];
int data[1001][4];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
	}
	
	
	int res = INT_MAX;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++) {
			if (k == i) dp[1][i] = data[1][i];
			else dp[1][i] = 1000 * 1000 + 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + data[i][j];
			}
		}
		for (int i = 0; i < 3; i++) {
			if (i == k) continue;
			res = min(res, dp[n][i]);
		}
	}
	
	printf("%d\n", res);
	return 0;
}