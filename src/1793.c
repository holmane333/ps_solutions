#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

char dp[1000][1000];
int check[1000];

void DP(int n) {
	if (n <= 0 || check[n]) return;
	check[n] = 1;
	int carry = 0, k = 0;
	for (int i = 0; i < 1000; i++) {
		if ((int)dp[n - 2][i] == 0 && (int)dp[n - 1][i] == 0 && carry == 0) break;
		k = (int)dp[n - 2][i] + (int)dp[n - 2][i] + (int)dp[n-1][i] - 48 * 3 + carry;
		if ((int)dp[n - 2][i] == 0) k += 48 * 2;
		if ((int)dp[n - 1][i] == 0) k += 48;
		dp[n][i] = (char)(k % 10 + 48);
		carry = k / 10;
	}
}

int main() {
	int n;
	memset(dp, 0, sizeof(dp));
	
	dp[0][0] = '1';
	dp[1][0] = '1';
	dp[2][0] = '3';
	
	while (scanf("%d", &n) != EOF) {
		for (int i = 3; i <= n; i++) {
			DP(i);
		}
		int c = 0;
		for (int i = 999; i >= 0; i--) {
			if (dp[n][i] != '\0') c = 1;
			if (c == 1) printf("%c", dp[n][i]);
		}
		puts("");
	}

	return 0;
}
